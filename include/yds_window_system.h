#ifndef YDS_WINDOW_SYSTEM_H
#define YDS_WINDOW_SYSTEM_H

#include "yds_dynamic_array.h"
#include "yds_window.h"
#include "yds_monitor.h"

class ysInputSystem;

class ysWindowSystem : public ysWindowSystemObject {
protected:
    // Singelton interface (necessary for WndProc which is a global function)
    static ysWindowSystem *Get();
    static ysWindowSystem *g_instance;

    ysWindowSystem();
    ysWindowSystem(Platform platform);
    virtual ~ysWindowSystem();

public:
    static ysError CreateWindowSystem(ysWindowSystem **newSystem, Platform platform);
    static ysError DestroyWindowSystem(ysWindowSystem *&system);

    // Window Interface
    virtual ysError NewWindow(ysWindow **window) = 0;

    int GetWindowCount() const;
    ysWindow *GetWindow(int index);
    void CloseWindow(ysWindow *window);
    void DeleteWindow(ysWindow *window);

    virtual void SetCursorPosition(int x, int y) { /* void */ }

    virtual void ConfineCursor(const ysWindow *window) { m_cursorConfined = true; }
    virtual void ReleaseCursor(const ysWindow *window) { m_cursorConfined = false; }
    bool IsCursorConfined() const { return m_cursorConfined; }

    virtual void SetCursorVisible(bool visible) { m_cursorVisible = visible; }
    bool IsMouseVisible() const { return m_cursorVisible; };

    // Monitor Interface
    virtual ysMonitor *NewMonitor() = 0;
    virtual void SurveyMonitors();

    void ClearMonitors();
    ysMonitor *GetPrimaryMonitor();
    ysMonitor *GetMonitor(int index);
    int GetNumMonitors();

    // Message Interface
    virtual void ProcessMessages() = 0;

    void CloseAllWindows();
    void DeleteInactiveWindows();
    void DeleteAllWindows();

    ysError AssignInputSystem(ysInputSystem *system);
    ysInputSystem *GetInputSystem() { return m_inputSystem; }

    // ms windows bullshit
    virtual void ConnectInstance(void *genericInstanceConnection) = 0;

protected:
    ysDynamicArray<ysMonitor, 4> m_monitorArray;
    ysDynamicArray<ysWindow, 4> m_windowArray;

    ysInputSystem *m_inputSystem;

    bool m_cursorVisible;
    bool m_cursorConfined;
};

#endif /* YDS_WINDOW_SYSTEM_H */
