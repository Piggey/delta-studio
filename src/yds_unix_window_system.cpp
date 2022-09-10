#include "../include/yds_unix_window_system.h"

#include "../include/yds_unix_window.h"
#include "../include/yds_unix_monitor.h"

#include <string>

#include <SDL2/SDL.h>

ysUnixWindowSystem::ysUnixWindowSystem() : ysWindowSystem(Platform::Linux) {
}

ysUnixWindowSystem::~ysUnixWindowSystem() {

}

ysError ysUnixWindowSystem::NewWindow(ysWindow **newWindow) {
    YDS_ERROR_DECLARE("NewWindow");

    if (newWindow == nullptr)
        YDS_ERROR_RETURN(ysError::InvalidParameter);

    auto* unixWindow = m_windowArray.NewGeneric<ysUnixWindow>();
    *newWindow = static_cast<ysWindow*>(unixWindow);

    return YDS_ERROR_RETURN(ysError::None);
}

ysMonitor *ysUnixWindowSystem::NewMonitor() {
    return m_monitorArray.NewGeneric<ysUnixMonitor>();
}

void ysUnixWindowSystem::SurveyMonitors() {
    ysWindowSystem::SurveyMonitors();

    // honestly i dont even know if the windows version is doing anything
    // the information isnt even stored anywhere
}

void ysUnixWindowSystem::ProcessMessages() {

}

void ysUnixWindowSystem::ConfineCursor(const ysWindow *window) {
    if (IsCursorConfined())
        return;

    ysWindowSystem::ConfineCursor(window);

    SDL_Rect rect;
    rect.x = window->GetPositionX();
    rect.y = window->GetPositionY();
    rect.w = window->GetScreenWidth();
    rect.h = window->GetScreenHeight();

    auto* unixWindow = dynamic_cast<const ysUnixWindow*>(window);
    SDL_SetWindowMouseRect(unixWindow->m_sdl_window, &rect);
}

void ysUnixWindowSystem::ReleaseCursor(const ysWindow *window) {
    if (!IsCursorConfined())
        return;

    ysWindowSystem::ReleaseCursor(window);

    auto* unixWindow = dynamic_cast<const ysUnixWindow*>(window);
    SDL_SetWindowMouseRect(unixWindow->m_sdl_window, NULL);
}

void ysUnixWindowSystem::SetCursorPosition(int x, int y) {
    SDL_WarpMouseGlobal(x, y);
}

void ysUnixWindowSystem::SetCursorVisible(bool visible) {
    ysWindowSystem::SetCursorVisible(visible);

    auto state = (visible) ? SDL_ENABLE : SDL_DISABLE;
    SDL_ShowCursor(state);
}



