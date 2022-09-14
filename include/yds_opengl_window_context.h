#ifndef YDS_OPENGL_WINDOWS_CONTEXT_H
#define YDS_OPENGL_WINDOWS_CONTEXT_H

#include "yds_opengl_context.h"

#if defined(_MSC_VER)
    #include "OpenGL.h"
#elif defined(__GNUC__)
    #include <GL/gl.h>
#endif

class ysOpenGLDevice;

class ysOpenGLWindowContext : public ysOpenGLVirtualContext {
    friend ysOpenGLDevice;

public:
    explicit ysOpenGLWindowContext(ysWindowSystemObject::Platform platform = ysWindowSystem::Platform::Windows);

    ~ysOpenGLWindowContext() override;

    ysError CreateRenderingContext(ysOpenGLDevice *device, ysWindow *window, int major, int minor);

    ysError DestroyContext() override;
    ysError TransferContext(ysOpenGLVirtualContext *context) override;
    ysError SetContextMode(ContextMode mode) override;
    ysError SetContext(ysRenderingContext *realContext) override;
    ysError Present() override;

protected:
    ysOpenGLDevice *m_device;
    SDL_GLContext m_glContext;
    SDL_Window* m_sdlWindow;

protected:
    void LoadAllExtensions();
};

#endif /* YDS_OPENGL_WINDOWS_CONTEXT_H */
