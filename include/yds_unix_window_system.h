#ifndef YDS_UNIX_WINDOW_SYSTEM_H
#define YDS_UNIX_WINDOW_SYSTEM_H

#include "yds_window_system.h"


class ysUnixWindowSystem : public ysWindowSystem {
public:
    ysUnixWindowSystem();
    ~ysUnixWindowSystem() override;

    ysError NewWindow(ysWindow **newWindow) override;

    ysMonitor *NewMonitor() override;
    void SurveyMonitors() override;

    void ProcessMessages() override;

    void SetCursorPosition(int x, int y) override;
    void ConfineCursor(const ysWindow *window) override;
    void ReleaseCursor(const ysWindow *window) override;
    void SetCursorVisible(bool visible) override;

    // empty function to keep compatibility
    void ConnectInstance(void *genericInstanceConnection) override { /* void */ }
};


#endif //YDS_UNIX_WINDOW_SYSTEM_H
