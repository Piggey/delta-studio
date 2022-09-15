#ifndef YDS_UNIX_WINDOW_H
#define YDS_UNIX_WINDOW_H

#include "yds_window.h"

#include <SDL2/SDL.h>

class ysUnixWindow : public ysWindow {
    friend class ysUnixWindowSystem;

public:
    ysUnixWindow();
    ~ysUnixWindow() override;

    ysError InitializeWindow(ysWindow *parent, const char *title, WindowStyle style, int x, int y, int width, int height, ysContextObject::DeviceAPI api, ysMonitor *monitor) override;
    ysError InitializeWindow(ysWindow *parent, const char *title, WindowStyle style, ysContextObject::DeviceAPI api, ysMonitor *monitor) override;

    bool SetWindowStyle(WindowStyle style) override;

    void ScreenToLocal(int &x, int &y) const override;

    bool IsVisible() override;

    SDL_Window *GetSDLWindow() const { return m_sdlWindow; }
    int GetScreenWidth() const override;
    int GetScreenHeight() const override;

private:
    SDL_Window* m_sdlWindow = nullptr;

};


#endif //YDS_UNIX_WINDOW_H
