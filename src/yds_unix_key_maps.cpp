#include "../include/yds_key_maps.h"

#include <SDL_scancode.h>

ysKey::Code *ysKeyMaps::m_keyMap;

const ysKey::Code *ysKeyMaps::GetUnixKeyMap() {
    if (m_keyMap != nullptr)
        return m_keyMap;

    m_keyMap = new ysKey::Code[512];
    for (int i = 0; i < 512; i++) {
        m_keyMap[i] = ysKey::Code::Undefined;
    }

    m_keyMap[SDL_SCANCODE_BACKSPACE] = ysKey::Code::Back;
    m_keyMap[SDL_SCANCODE_TAB] = ysKey::Code::Tab;

    m_keyMap[SDL_SCANCODE_CLEAR] = ysKey::Code::Clear;

    m_keyMap[SDL_SCANCODE_RETURN] = ysKey::Code::Return;

    m_keyMap[SDL_SCANCODE_MENU] = ysKey::Code::Menu;
    m_keyMap[SDL_SCANCODE_PAUSE] = ysKey::Code::Pause;
    m_keyMap[SDL_SCANCODE_CAPSLOCK] = ysKey::Code::CapsLock;

    m_keyMap[SDL_SCANCODE_ESCAPE] = ysKey::Code::Escape;
    m_keyMap[SDL_SCANCODE_MODE] = ysKey::Code::ModeChange;

    m_keyMap[SDL_SCANCODE_SPACE] = ysKey::Code::Space;
    m_keyMap[SDL_SCANCODE_PAGEUP] = ysKey::Code::PageUp;
    m_keyMap[SDL_SCANCODE_PAGEDOWN] = ysKey::Code::PageDown;
    m_keyMap[SDL_SCANCODE_END] = ysKey::Code::End;
    m_keyMap[SDL_SCANCODE_HOME] = ysKey::Code::Home;

    m_keyMap[SDL_SCANCODE_LEFT] = ysKey::Code::Left;
    m_keyMap[SDL_SCANCODE_UP] = ysKey::Code::Up;
    m_keyMap[SDL_SCANCODE_RIGHT] = ysKey::Code::Right;
    m_keyMap[SDL_SCANCODE_DOWN] = ysKey::Code::Down;

    m_keyMap[SDL_SCANCODE_SELECT] = ysKey::Code::Select;
    m_keyMap[SDL_SCANCODE_PRINTSCREEN] = ysKey::Code::PrintScreen;
    m_keyMap[SDL_SCANCODE_INSERT] = ysKey::Code::Insert;
    m_keyMap[SDL_SCANCODE_DELETE] = ysKey::Code::Delete;
    m_keyMap[SDL_SCANCODE_HELP] = ysKey::Code::Help;

    // 0 - 9 keys
    m_keyMap[SDL_SCANCODE_0] = ysKey::Code::N0;
    for (int i = 0; i < 9; i++) {
        m_keyMap[SDL_SCANCODE_1 + i] = (ysKey::Code) ((int)ysKey::Code::N1 + i);
    }

    // a - z keys
    for (int i = 0; i < 26; i++) {
        m_keyMap[SDL_SCANCODE_A + i] = (ysKey::Code) ((int) ysKey::Code::A + i);
    }

    m_keyMap[SDL_SCANCODE_LGUI] = ysKey::Code::LeftWin;
    m_keyMap[SDL_SCANCODE_RGUI] = ysKey::Code::RightWin;
    m_keyMap[SDL_SCANCODE_APPLICATION] = ysKey::Code::Apps;
    m_keyMap[SDL_SCANCODE_SLEEP] = ysKey::Code::Sleep;

    // numpad keys
    m_keyMap[SDL_SCANCODE_KP_0] = ysKey::Code::Numpad0;
    for (int i = 0; i < 9; i++) {
        m_keyMap[SDL_SCANCODE_KP_1 + i] = (ysKey::Code)((int) ysKey::Code::Numpad1 + i);
    }

    // for some reason SDL has shift versions of these keys
    m_keyMap[SDL_SCANCODE_EQUALS] = ysKey::Code::Add;
    m_keyMap[SDL_SCANCODE_BACKSLASH] = ysKey::Code::Separator;
    m_keyMap[SDL_SCANCODE_MINUS] = ysKey::Code::Subtract;
    m_keyMap[SDL_SCANCODE_DECIMALSEPARATOR] = ysKey::Code::Decimal;
    m_keyMap[SDL_SCANCODE_SLASH] = ysKey::Code::Divide;

    // F1 - F23 function keys
    for (int i = 0; i < 12; i++) {
        m_keyMap[SDL_SCANCODE_F1 + i] = (ysKey::Code)((int) ysKey::Code::F1 + i);
        m_keyMap[SDL_SCANCODE_F13 + i] = (ysKey::Code)((int) ysKey::Code::F13 + i);
    }

    m_keyMap[SDL_SCANCODE_NUMLOCKCLEAR] = ysKey::Code::NumLock;
    m_keyMap[SDL_SCANCODE_SCROLLLOCK] = ysKey::Code::ScrollLock;
    m_keyMap[SDL_SCANCODE_LSHIFT] = ysKey::Code::LeftShift;
    m_keyMap[SDL_SCANCODE_RSHIFT] = ysKey::Code::RightShift;
    m_keyMap[SDL_SCANCODE_LCTRL] = ysKey::Code::LeftControl;
    m_keyMap[SDL_SCANCODE_RCTRL] = ysKey::Code::RightControl;
    m_keyMap[SDL_SCANCODE_LALT] = ysKey::Code::LeftMenu;
    m_keyMap[SDL_SCANCODE_RALT] = ysKey::Code::RightMenu;

    // browser keys
    m_keyMap[SDL_SCANCODE_AC_BACK] = ysKey::Code::BrowserBack;
    m_keyMap[SDL_SCANCODE_AC_FORWARD] = ysKey::Code::BrowserForward;
    m_keyMap[SDL_SCANCODE_AC_REFRESH] = ysKey::Code::BrowserRefresh;
    m_keyMap[SDL_SCANCODE_AC_STOP] = ysKey::Code::BrowserStop;

    m_keyMap[SDL_SCANCODE_AC_SEARCH] = ysKey::Code::BrowserSearch;
    m_keyMap[SDL_SCANCODE_AC_BOOKMARKS] = ysKey::Code::BrowserFavorites;
    m_keyMap[SDL_SCANCODE_AC_HOME] = ysKey::Code::BrowserHome;

    // media keys
    m_keyMap[SDL_SCANCODE_MUTE] = ysKey::Code::VolumeMute;
    m_keyMap[SDL_SCANCODE_VOLUMEDOWN] = ysKey::Code::VolumeDown;
    m_keyMap[SDL_SCANCODE_VOLUMEUP] = ysKey::Code::VolumeUp;
    m_keyMap[SDL_SCANCODE_AUDIONEXT] = ysKey::Code::MediaNextTrack;
    m_keyMap[SDL_SCANCODE_AUDIOPREV] = ysKey::Code::MediaPrevTrack;
    m_keyMap[SDL_SCANCODE_AUDIOSTOP] = ysKey::Code::MediaStop;
    m_keyMap[SDL_SCANCODE_AUDIOPLAY] = ysKey::Code::MediaPlay;

    m_keyMap[SDL_SCANCODE_MAIL] = ysKey::Code::LaunchMail;
    m_keyMap[SDL_SCANCODE_MEDIASELECT] = ysKey::Code::LaunchMediaSelect;

    m_keyMap[SDL_SCANCODE_APP1] = ysKey::Code::LaunchApp1;
    m_keyMap[SDL_SCANCODE_APP2] = ysKey::Code::LaunchApp2;

    m_keyMap[0xff] = ysKey::Code::Function;

    return m_keyMap;
}

#undef KEYCODE_TO_SCANCODE
