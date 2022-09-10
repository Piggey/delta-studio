#include "../include/yds_unix_window.h"

ysUnixWindow::ysUnixWindow() : ysWindow(Platform::Linux) {

}

ysUnixWindow::~ysUnixWindow() {

}

ysError ysUnixWindow::InitializeWindow(ysWindow *parent, const char *title, ysWindow::WindowStyle style,
                                       int x, int y, int width, int height, ysMonitor *monitor) {
    YDS_ERROR_DECLARE("InitializeWindow");

    if (!CheckCompatibility(parent))
        return YDS_ERROR_RETURN(ysError::IncompatiblePlatforms);

    YDS_NESTED_ERROR_CALL(ysWindow::InitializeWindow(parent, title, style, x, y, width, height, monitor));

    // init a window using SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return YDS_ERROR_RETURN(ysError::ApiError);
    }

    // actually create a window
    m_sdl_window = SDL_CreateWindow(
            title,
            x, y,
            width, height,
            SDL_WINDOW_SHOWN
    );

    if (m_sdl_window == NULL) {
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
    if (m_sdl_window == nullptr)
        return false;

    if (!ysWindow::SetWindowStyle(style))
        return false;

    if (style == WindowStyle::Windowed ||
        style == WindowStyle::Popup) {
        const int width = GetScreenWidth();
        const int height = GetScreenHeight();

        const int x = GetPositionX();
        const int y = GetPositionY();

        SDL_SetWindowPosition(m_sdl_window, x, y);
        SDL_SetWindowSize(m_sdl_window, width, height);

        SDL_ShowWindow(m_sdl_window);
    }
    else if (style == WindowStyle::Fullscreen) {
        SDL_SetWindowFullscreen(m_sdl_window, SDL_WINDOW_FULLSCREEN_DESKTOP);

        SDL_ShowWindow(m_sdl_window);
    }

    return true;
}

void ysUnixWindow::ScreenToLocal(int &x, int &y) const {
    if (m_sdl_window == nullptr) {
        x = y = 0;
        return;
    }
    // there isnt really a function like that in SDL2 so ill just leave x and y as is
    // (to my knowledge)
}

bool ysUnixWindow::IsVisible() {
    if (m_sdl_window == nullptr)
        return false;

    auto flags = SDL_GetWindowFlags(m_sdl_window);

    if (flags & SDL_WINDOW_HIDDEN)
        return false;
    else
        return true;
}

int ysUnixWindow::GetScreenWidth() const {
    if (m_sdl_window == nullptr)
        return 0;

    int w;
    SDL_GetWindowSize(m_sdl_window, &w, nullptr);

    return w;
}

int ysUnixWindow::GetScreenHeight() const {
    if (m_sdl_window == nullptr)
        return 0;

    int h;
    SDL_GetWindowSize(m_sdl_window, nullptr, &h);

    return h;
}



