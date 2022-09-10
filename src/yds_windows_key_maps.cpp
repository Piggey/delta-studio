#include "../include/yds_key_maps.h"

#include <Windows.h>

ysKey::Code *ysKeyMaps::m_keyMap;

const ysKey::Code *ysKeyMaps::GetWindowsKeyMap() {
    if (m_keyMap == NULL) {
        m_keyMap = new ysKey::Code[256];

        for (int i = 0; i < 256; ++i)
            m_keyMap[i] = ysKey::Code::Undefined;

        m_keyMap[VK_BACK] = ysKey::Code::Back;
        m_keyMap[VK_TAB] = ysKey::Code::Tab;

        m_keyMap[VK_CLEAR] = ysKey::Code::Clear;

        m_keyMap[VK_RETURN] = ysKey::Code::Return;
        m_keyMap[VK_SHIFT] = ysKey::Code::Shift;
        m_keyMap[VK_CONTROL] = ysKey::Code::Control;

        m_keyMap[VK_MENU] = ysKey::Code::Menu;
        m_keyMap[VK_PAUSE] = ysKey::Code::Pause;
        m_keyMap[VK_CAPITAL] = ysKey::Code::CapsLock;

        m_keyMap[VK_ESCAPE] = ysKey::Code::Escape;
        m_keyMap[VK_CONVERT] = ysKey::Code::Convert;
        m_keyMap[VK_NONCONVERT] = ysKey::Code::NonConvert;
        m_keyMap[VK_ACCEPT] = ysKey::Code::Accept;
        m_keyMap[VK_MODECHANGE] = ysKey::Code::ModeChange;

        m_keyMap[VK_SPACE] = ysKey::Code::Space;
        m_keyMap[VK_PRIOR] = ysKey::Code::PageUp;
        m_keyMap[VK_NEXT] = ysKey::Code::PageDown;
        m_keyMap[VK_END] = ysKey::Code::End;
        m_keyMap[VK_HOME] = ysKey::Code::Home;

        m_keyMap[VK_LEFT] = ysKey::Code::Left;
        m_keyMap[VK_UP] = ysKey::Code::Up;
        m_keyMap[VK_RIGHT] = ysKey::Code::Right;
        m_keyMap[VK_DOWN] = ysKey::Code::Down;

        m_keyMap[VK_SELECT] = ysKey::Code::Select;
        m_keyMap[VK_PRINT] = ysKey::Code::Print;
        m_keyMap[VK_SNAPSHOT] = ysKey::Code::PrintScreen;
        m_keyMap[VK_INSERT] = ysKey::Code::Insert;
        m_keyMap[VK_DELETE] = ysKey::Code::Delete;
        m_keyMap[VK_HELP] = ysKey::Code::Help;

        // 0 - 9 keys
        for (int i = 0; i < 10; ++i) m_keyMap[0x30 + i] = (ysKey::Code)((int)ysKey::Code::N0 + i);

        // A - Z keys
        for (int i = 0; i < 26; ++i) m_keyMap[0x41 + i] = (ysKey::Code)((int)ysKey::Code::A + i);

        m_keyMap[VK_LWIN] = ysKey::Code::LeftWin;
        m_keyMap[VK_RWIN] = ysKey::Code::RightWin;
        m_keyMap[VK_APPS] = ysKey::Code::Apps;

        m_keyMap[VK_SLEEP] = ysKey::Code::Sleep;

        // Numpad keys
        for (int i = 0; i < 10; ++i)
            m_keyMap[VK_NUMPAD0 + i] = (ysKey::Code)((int)ysKey::Code::Numpad0 + i);

        m_keyMap[VK_ADD] = ysKey::Code::Add;
        m_keyMap[VK_SEPARATOR] = ysKey::Code::Separator;
        m_keyMap[VK_SUBTRACT] = ysKey::Code::Subtract;
        m_keyMap[VK_DECIMAL] = ysKey::Code::Decimal;
        m_keyMap[VK_DIVIDE] = ysKey::Code::Divide;
        m_keyMap[VK_MULTIPLY] = ysKey::Code::Multiply;

        // F keys
        for (int i = 0; i < 24; ++i)
            m_keyMap[VK_F1 + i] = (ysKey::Code)((int)ysKey::Code::F1 + i);

        m_keyMap[VK_NUMLOCK] = ysKey::Code::NumLock;
        m_keyMap[VK_SCROLL] = ysKey::Code::ScrollLock;
        m_keyMap[VK_LSHIFT] = ysKey::Code::LeftShift;
        m_keyMap[VK_RSHIFT] = ysKey::Code::RightShift;
        m_keyMap[VK_LCONTROL] = ysKey::Code::LeftControl;
        m_keyMap[VK_RCONTROL] = ysKey::Code::RightControl;
        m_keyMap[VK_LMENU] = ysKey::Code::LeftMenu;
        m_keyMap[VK_RMENU] = ysKey::Code::RightMenu;

        m_keyMap[VK_BROWSER_BACK] = ysKey::Code::BrowserBack;
        m_keyMap[VK_BROWSER_FORWARD] = ysKey::Code::BrowserForward;
        m_keyMap[VK_BROWSER_REFRESH] = ysKey::Code::BrowserRefresh;
        m_keyMap[VK_BROWSER_STOP] = ysKey::Code::BrowserStop;

        m_keyMap[VK_BROWSER_SEARCH] = ysKey::Code::BrowserSearch;
        m_keyMap[VK_BROWSER_FAVORITES] = ysKey::Code::BrowserFavorites;
        m_keyMap[VK_BROWSER_HOME] = ysKey::Code::BrowserHome;

        m_keyMap[VK_VOLUME_MUTE] = ysKey::Code::VolumeMute;
        m_keyMap[VK_VOLUME_DOWN] = ysKey::Code::VolumeDown;
        m_keyMap[VK_VOLUME_UP] = ysKey::Code::VolumeUp;
        m_keyMap[VK_MEDIA_NEXT_TRACK] = ysKey::Code::MediaNextTrack;
        m_keyMap[VK_MEDIA_PREV_TRACK] = ysKey::Code::MediaPrevTrack;
        m_keyMap[VK_MEDIA_STOP] = ysKey::Code::MediaStop;
        m_keyMap[VK_MEDIA_PLAY_PAUSE] = ysKey::Code::MediaPlay;
        m_keyMap[VK_LAUNCH_MAIL] = ysKey::Code::LaunchMail;
        m_keyMap[VK_LAUNCH_MEDIA_SELECT] = ysKey::Code::LaunchMediaSelect;

        m_keyMap[VK_LAUNCH_APP1] = ysKey::Code::LaunchApp1;
        m_keyMap[VK_LAUNCH_APP2] = ysKey::Code::LaunchApp2;

        m_keyMap[VK_OEM_PLUS] = ysKey::Code::OEM_Plus;
        m_keyMap[VK_OEM_COMMA] = ysKey::Code::OEM_Comma;
        m_keyMap[VK_OEM_MINUS] = ysKey::Code::OEM_Minus;
        m_keyMap[VK_OEM_PERIOD] = ysKey::Code::OEM_Period;
        m_keyMap[VK_OEM_CLEAR] = ysKey::Code::OEM_Clear;

        m_keyMap[VK_OEM_1] = ysKey::Code::OEM_1;
        m_keyMap[VK_OEM_2] = ysKey::Code::OEM_2;
        m_keyMap[VK_OEM_3] = ysKey::Code::OEM_3;
        m_keyMap[VK_OEM_4] = ysKey::Code::OEM_4;
        m_keyMap[VK_OEM_5] = ysKey::Code::OEM_5;
        m_keyMap[VK_OEM_6] = ysKey::Code::OEM_6;
        m_keyMap[VK_OEM_7] = ysKey::Code::OEM_7;
        m_keyMap[VK_OEM_8] = ysKey::Code::OEM_8;

        m_keyMap[VK_PLAY] = ysKey::Code::Play;
        m_keyMap[VK_ZOOM] = ysKey::Code::Zoom;

        m_keyMap[0xff] = ysKey::Code::Function;
    }

    return m_keyMap;
}
