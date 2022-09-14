#include "../include/yds_opengl_windows_context.h"

#include "../include/yds_opengl_device.h"
#include "../include/yds_window.h"

#include <SDL2/SDL.h>

ysOpenGLWindowsContext::ysOpenGLWindowsContext(ysWindowSystemObject::Platform platform) : ysOpenGLVirtualContext(platform) {
    m_device = nullptr;
}

ysOpenGLWindowsContext::~ysOpenGLWindowsContext() {
    /* void */
}

ysError ysOpenGLWindowsContext::CreateRenderingContext(ysOpenGLDevice *device, ysWindow *window, int major, int minor) {
    YDS_ERROR_DECLARE("CreateRenderingContext");

    if (window->GetPlatform() == ysWindowSystemObject::Platform::Unknown) {
        return YDS_ERROR_RETURN(ysError::IncompatiblePlatforms);
    }

    // init SDL
    int init_result = SDL_Init(SDL_INIT_VIDEO);

    if (init_result != 0) {
        fprintf(stderr, "%s\n", SDL_GetError());
    }

    // set pixel stuff
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // create SDL window
    m_window = SDL_CreateWindow(
        window->GetTitle(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        window->GetWidth(),
        window->GetHeight(),
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN | SDL_WINDOW_MOUSE_CAPTURE
    );

    // generate context
    *m_context = SDL_GL_CreateContext(m_window);

    if (m_context == nullptr) {
        fprintf(stderr, "%s\n", SDL_GetError());
        return YDS_ERROR_RETURN(ysError::CouldNotCreateContext);
    }

    if(SDL_GL_MakeCurrent(m_window, m_context) != 0) {
        fprintf(stderr, "%s\n", SDL_GetError());
        return YDS_ERROR_RETURN(ysError::CouldNotActivateTemporaryContext);
    }

    m_isRealContext = true;
    device->UpdateContext();

    m_device = device;
    m_targetWindow = window;

    LoadAllExtensions();

    return YDS_ERROR_RETURN(ysError::None);
}

ysError ysOpenGLWindowsContext::DestroyContext() {
    YDS_ERROR_DECLARE("DestroyContext");

    SDL_GL_DeleteContext(m_context);
    SDL_DestroyWindow(m_window);

    return YDS_ERROR_RETURN(ysError::None);
}

ysError ysOpenGLWindowsContext::TransferContext(ysOpenGLVirtualContext *context) {
    YDS_ERROR_DECLARE("TransferContext");

    if (context->GetPlatform() == ysWindowSystemObject::Platform::Unknown) 
        return YDS_ERROR_RETURN(ysError::IncompatiblePlatforms);

    ysOpenGLWindowsContext *windowsContext = static_cast<ysOpenGLWindowsContext *>(context);
    windowsContext->m_context = m_context;
    windowsContext->m_isRealContext = true;

    m_isRealContext = false;

    return YDS_ERROR_RETURN(ysError::None);
}

ysError ysOpenGLWindowsContext::SetContextMode(ContextMode mode) {
    YDS_ERROR_DECLARE("SetContextMode");

    ysWindow *window = GetWindow();
    ysMonitor *monitor = window->GetMonitor();
    int result;

    if (mode == ysRenderingContext::ContextMode::Fullscreen) {
        window->SetWindowStyle(ysWindow::WindowStyle::Fullscreen);

        SDL_DisplayMode mode;
        mode.format = SDL_PIXELFORMAT_RGBA8888;
        mode.h = monitor->GetPhysicalHeight();
        mode.w = monitor->GetPhysicalWidth();
        mode.refresh_rate = 0;
        mode.driverdata = 0;

        if (SDL_SetWindowDisplayMode(m_window, &mode) != 0) {
            return YDS_ERROR_RETURN(ysError::CouldNotEnterFullscreen);
        }
    }
    else if (mode == ysRenderingContext::ContextMode::Windowed) {
        window->SetWindowStyle(ysWindow::WindowStyle::Windowed);

        if (SDL_SetWindowDisplayMode(m_window, NULL) != 0) {
            return YDS_ERROR_RETURN(ysError::CouldNotExitFullscreen);
        }
    }

    return YDS_ERROR_RETURN(ysError::None);
}

ysError ysOpenGLWindowsContext::SetContext(ysRenderingContext *realContext) {
    YDS_ERROR_DECLARE("SetContext");

    if (realContext == nullptr) {
        SDL_GL_MakeCurrent(NULL, NULL);
        return YDS_ERROR_RETURN(ysError::NoContext);
    }

    ysOpenGLWindowsContext *realOpenglContext = static_cast<ysOpenGLWindowsContext *>(realContext);

    if (SDL_GL_MakeCurrent(m_window, realOpenglContext->m_context) != 0) {
        fprintf(stderr, "%s\n", SDL_GetError());
        return YDS_ERROR_RETURN(ysError::CouldNotActivateContext);
    }

    return YDS_ERROR_RETURN(ysError::None);
}

ysError ysOpenGLWindowsContext::Present() {
    YDS_ERROR_DECLARE("Present");

    SDL_GL_SwapWindow(m_window);
    return YDS_ERROR_RETURN(ysError::None);
}


void ysOpenGLWindowsContext::LoadAllExtensions() {
    glGenBuffers = (PFNGLGENBUFFERSPROC)SDL_GL_GetProcAddress("glGenBuffers");
    glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)SDL_GL_GetProcAddress("glDeleteBuffers");
    glBindBuffer = (PFNGLBINDBUFFERPROC)SDL_GL_GetProcAddress("glBindBuffer");
    glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)SDL_GL_GetProcAddress("glBindBufferRange");
    glBufferData = (PFNGLBUFFERDATAPROC)SDL_GL_GetProcAddress("glBufferData");
    glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)SDL_GL_GetProcAddress("glGenVertexArrays");
    glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)SDL_GL_GetProcAddress("glDeleteVertexArrays");
    glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)SDL_GL_GetProcAddress("glBindVertexArray");
    glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)SDL_GL_GetProcAddress("glEnableVertexAttribArray");
    glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)SDL_GL_GetProcAddress("glVertexAttribPointer");
    glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)SDL_GL_GetProcAddress("glVertexAttribIPointer");
    glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)SDL_GL_GetProcAddress("glVertexAttrib3f");
    glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)SDL_GL_GetProcAddress("glVertexAttrib4f");

    // Shaders
    glDeleteShader = (PFNGLDELETESHADERPROC)SDL_GL_GetProcAddress("glDeleteShader");
    glDeleteProgram = (PFNGLDELETEPROGRAMPROC)SDL_GL_GetProcAddress("glDeleteProgram");

    glCreateShader = (PFNGLCREATESHADERPROC)SDL_GL_GetProcAddress("glCreateShader");
    glShaderSource = (PFNGLSHADERSOURCEPROC)SDL_GL_GetProcAddress("glShaderSource");
    glCompileShader = (PFNGLCOMPILESHADERPROC)SDL_GL_GetProcAddress("glCompileShader");
    glCreateProgram = (PFNGLCREATEPROGRAMPROC)SDL_GL_GetProcAddress("glCreateProgram");
    glAttachShader = (PFNGLATTACHSHADERPROC)SDL_GL_GetProcAddress("glAttachShader");
    glDetachShader = (PFNGLDETACHSHADERPROC)SDL_GL_GetProcAddress("glDetachShader");
    glLinkProgram = (PFNGLLINKPROGRAMPROC)SDL_GL_GetProcAddress("glLinkProgram");
    glUseProgram = (PFNGLUSEPROGRAMPROC)SDL_GL_GetProcAddress("glUseProgram");
    glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)SDL_GL_GetProcAddress("glBindAttribLocation");
    glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)SDL_GL_GetProcAddress("glBindFragDataLocation");
    glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)SDL_GL_GetProcAddress("glGetFragDataLocation");
    glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)SDL_GL_GetProcAddress("glGetUniformLocation");
    glGetShaderiv = (PFNGLGETSHADERIVPROC)SDL_GL_GetProcAddress("glGetShaderiv");
    glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)SDL_GL_GetProcAddress("glGetShaderInfoLog");
    glDrawBuffers = (PFNGLDRAWBUFFERSPROC)SDL_GL_GetProcAddress("glDrawBuffers");

    glUniform4fv = (PFNGLUNIFORM4FVPROC)SDL_GL_GetProcAddress("glUniform4fv");
    glUniform3fv = (PFNGLUNIFORM3FVPROC)SDL_GL_GetProcAddress("glUniform3fv");
    glUniform2fv = (PFNGLUNIFORM2FVPROC)SDL_GL_GetProcAddress("glUniform2fv");
    glUniform4f = (PFNGLUNIFORM4FPROC)SDL_GL_GetProcAddress("glUniform4f");
    glUniform3f = (PFNGLUNIFORM3FPROC)SDL_GL_GetProcAddress("glUniform3f");
    glUniform2f = (PFNGLUNIFORM2FPROC)SDL_GL_GetProcAddress("glUniform2f");
    glUniform1f = (PFNGLUNIFORM1FPROC)SDL_GL_GetProcAddress("glUniform1f");
    glUniform1i = (PFNGLUNIFORM1IPROC)SDL_GL_GetProcAddress("glUniform1i");

    glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)SDL_GL_GetProcAddress("glUniformMatrix4fv");
    glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)SDL_GL_GetProcAddress("glUniformMatrix3fv");

    glGetProgramiv = (PFNGLGETPROGRAMIVPROC)SDL_GL_GetProcAddress("glGetProgramiv");

    glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)SDL_GL_GetProcAddress("glGetActiveUniformName");
    glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)SDL_GL_GetProcAddress("glGetActiveUniformsiv");
    glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)SDL_GL_GetProcAddress("glGetActiveUniform");

    glMapBuffer = (PFNGLMAPBUFFERPROC)SDL_GL_GetProcAddress("glMapBuffer");
    glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)SDL_GL_GetProcAddress("glMapBufferRange");
    glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)SDL_GL_GetProcAddress("glUnmapBuffer");

    glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)SDL_GL_GetProcAddress("glDrawElementsBaseVertex");

    // Textures
    glActiveTexture = (PFNGLACTIVETEXTUREPROC)SDL_GL_GetProcAddress("glActiveTexture");
    glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)SDL_GL_GetProcAddress("glGenerateMipmap");

    glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)SDL_GL_GetProcAddress("glTexImage2DMultisample");

    // Buffers
    glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)SDL_GL_GetProcAddress("glGenRenderbuffers");
    glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)SDL_GL_GetProcAddress("glDeleteRenderbuffers");
    glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)SDL_GL_GetProcAddress("glBindRenderbuffer");
    glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)SDL_GL_GetProcAddress("glRenderbufferStorage");
    glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)SDL_GL_GetProcAddress("glRenderbufferStorageMultisample");
    glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)SDL_GL_GetProcAddress("glCopyBufferSubData");
    glBufferSubData = (PFNGLBUFFERSUBDATAPROC)SDL_GL_GetProcAddress("glBufferSubData");

    glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)SDL_GL_GetProcAddress("glGenFramebuffers");
    glDeleteFramebuffers = (PFNGLDELETERENDERBUFFERSPROC)SDL_GL_GetProcAddress("glDeleteFramebuffers");
    glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)SDL_GL_GetProcAddress("glBindFramebuffer");
    glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)SDL_GL_GetProcAddress("glFramebufferTexture2D");
    glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)SDL_GL_GetProcAddress("glFramebufferRenderbuffer");
    glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)SDL_GL_GetProcAddress("glCheckFramebufferStatus");

    glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)SDL_GL_GetProcAddress("glBlitFramebuffer");

    // Blending
    glBlendEquation = (PFNGLBLENDEQUATIONPROC)SDL_GL_GetProcAddress("glBlendEquation");
}

