#include "../include/yds_unix_window.h"

ysUnixWindow::ysUnixWindow() : ysWindow(Platform::Linux) {

}

ysUnixWindow::~ysUnixWindow() {
    SDL_DestroyWindow(m_sdlWindow);
}

ysError ysUnixWindow::InitializeWindow(ysWindow *parent, const char *title, ysWindow::WindowStyle style,
                                       int x, int y, int width, int height, ysMonitor *monitor) {
    YDS_ERROR_DECLARE("InitializeWindow");

    if (!CheckCompatibility(parent))
        return YDS_ERROR_RETURN(ysError::IncompatiblePlatforms);

    YDS_NESTED_ERROR_CALL(ysWindow::InitializeWindow(parent, title, style, x, y, width, height, monitor));

    // SDL2 should be initialized by now
    // actually create a window
    m_sdlWindow = SDL_CreateWindow(
            title,
            x, y,
            width, height,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );

    if (m_sdlWindow == nullptr) {
        return YDS_ERROR_RETURN(ysError::CouldNotCreateContext);
    }

    return YDS_ERROR_RETURN(ysError::None);
}

ysError ysUnixWindow::InitializeWindow(ysWindow *parent, const char *title,
                                       ysWindow::WindowStyle style,ysMonitor *monitor) {
    YDS_ERROR_DECLARE("InitializeWindow");
    YDS_NESTED_ERROR_CALL(
            InitializeWindow(
                parent,
                title,
                style,
                monitor->GetOriginX(),
                monitor->GetOriginY(),
                monitor->GetPhysicalWidth(),
                monitor->GetPhysicalHeight(),
                monitor
            )
    );

    YDS_ERROR_RETURN(ysError::None);
}

bool ysUnixWindow::SetWindowStyle(ysWindow::WindowStyle style) {
    if (m_sdlWindow == nullptr)
        return false;

    if (!ysWindow::SetWindowStyle(style))
        return false;

    if (style == WindowStyle::Windowed ||
        style == WindowStyle::Popup) {
        const int width = GetScreenWidth();
        const int height = GetScreenHeight();

        const int x = GetPositionX();
        const int y = GetPositionY();

        SDL_SetWindowPosition(m_sdlWindow, x, y);
        SDL_SetWindowSize(m_sdlWindow, width, height);

        SDL_ShowWindow(m_sdlWindow);
    }
    else if (style == WindowStyle::Fullscreen) {
        SDL_SetWindowFullscreen(m_sdlWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);

        SDL_ShowWindow(m_sdlWindow);
    }

    return true;
}

void ysUnixWindow::ScreenToLocal(int &x, int &y) const {
    if (m_sdlWindow == nullptr) {
        x = y = 0;
        return;
    }
    // there isnt really a function like that in SDL2 so ill just leave x and y as is
    // (to my knowledge)
}

bool ysUnixWindow::IsVisible() {
    if (m_sdlWindow == nullptr)
        return false;

    auto flags = SDL_GetWindowFlags(m_sdlWindow);

    if (flags & SDL_WINDOW_HIDDEN)
        return false;
    else
        return true;
}

int ysUnixWindow::GetScreenWidth() const {
    if (m_sdlWindow == nullptr)
        return 0;

    int w;
    SDL_GetWindowSize(m_sdlWindow, &w, nullptr);

    return w;
}

int ysUnixWindow::GetScreenHeight() const {
    if (m_sdlWindow == nullptr)
        return 0;

    int h;
    SDL_GetWindowSize(m_sdlWindow, nullptr, &h);

    return h;
}
