#ifndef YDS_UNIX_WINDOW_H
#define YDS_UNIX_WINDOW_H

#include "yds_window.h"

#include <SDL2/SDL.h>

class ysUnixWindowSystem;

class ysUnixWindow : public ysWindow {
    friend ysUnixWindowSystem;

public:
    ysUnixWindow();
    ~ysUnixWindow() override;

    ysError InitializeWindow(ysWindow *parent, const char *title, WindowStyle style, int x, int y, int width, int height, ysMonitor *monitor) override;
    ysError InitializeWindow(ysWindow *parent, const char *title, WindowStyle style, ysMonitor *monitor) override;

    bool SetWindowStyle(WindowStyle style) override;

    void ScreenToLocal(int &x, int &y) const override;

    bool IsVisible() override;

    int GetScreenWidth() const override;
    int GetScreenHeight() const override;

private:
    SDL_Window* m_sdl_window = nullptr;
};


#endif //YDS_UNIX_WINDOW_H
