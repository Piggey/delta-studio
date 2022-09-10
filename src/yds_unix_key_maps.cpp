#include "../include/yds_key_maps.h"

#include <SDL2/SDL_keycode.h>

#define KEYCODE_TO_SCANCODE(code) code ^ (1 << 30)

ysKey::Code *ysKeyMaps::m_keyMap;

const ysKey::Code *ysKeyMaps::GetUnixKeyMap() {
    if (m_keyMap != nullptr)
        return m_keyMap;

    m_keyMap = new ysKey::Code[256];

/* VALID KEYCODES [0, 255] */
    m_keyMap[SDLK_BACKSPACE] = ysKey::Code::Back;
    m_keyMap[SDLK_TAB] = ysKey::Code::Tab;
    m_keyMap[SDLK_RETURN] = ysKey::Code::Return;
    m_keyMap[SDLK_ESCAPE] = ysKey::Code::Escape;
    m_keyMap[SDLK_SPACE] = ysKey::Code::Space;
    m_keyMap[SDLK_DELETE] = ysKey::Code::Delete;

    // 0 - 9 number keys
    for (int i = 0; i < 10; i++) {
        m_keyMap[SDLK_0 + i] = (ysKey::Code) ((int) ysKey::Code::N0 + i);
    }

    // A - Z keys
    for (int i = 0; i < 26; i++) {
        m_keyMap[SDLK_a + i] = (ysKey::Code) ((int) ysKey::Code::A + i);
    }

    // i think they are the same since you change it with shift key
    m_keyMap[SDLK_EQUALS] = ysKey::Code::Add;
    m_keyMap[SDLK_UNDERSCORE] = ysKey::Code::Subtract;
    m_keyMap[SDLK_QUESTION] = ysKey::Code::Divide;

    m_keyMap[255] = ysKey::Code::Function;

/* NON-VALID KEYCODES (values out of range) */
    // im not even sure if itll work to be honest
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_CLEAR)] = ysKey::Code::Clear;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_LSHIFT)] = ysKey::Code::LeftShift;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_RSHIFT)] = ysKey::Code::RightShift;

    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_LCTRL)] = ysKey::Code::LeftControl;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_RCTRL)] = ysKey::Code::RightControl;

    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_MENU)] = ysKey::Code::Menu;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_PAUSE)] = ysKey::Code::Pause;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_CAPSLOCK)] = ysKey::Code::CapsLock;

    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_PAGEUP)] = ysKey::Code::PageUp;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_PAGEDOWN)] = ysKey::Code::PageDown;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_END)] = ysKey::Code::End;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_HOME)] = ysKey::Code::Home;

    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_LEFT)] = ysKey::Code::Left;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_RIGHT)] = ysKey::Code::Right;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_UP)] = ysKey::Code::Up;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_DOWN)] = ysKey::Code::Down;

    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_SELECT)] = ysKey::Code::Select;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_PRINTSCREEN)] = ysKey::Code::PrintScreen;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_INSERT)] = ysKey::Code::Insert;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_HELP)] = ysKey::Code::Help;

    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_LGUI)] = ysKey::Code::LeftWin;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_RGUI)] = ysKey::Code::RightWin;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_APPLICATION)] = ysKey::Code::Apps;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_SLEEP)] = ysKey::Code::Sleep;

    // numpad keys
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_KP_0)] = ysKey::Code::Numpad0;
    for (int i = 0; i < 9; i++) {
        m_keyMap[KEYCODE_TO_SCANCODE(SDLK_KP_1 + i)] = (ysKey::Code) ((int) ysKey::Code::Numpad1 + i);
    }

    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_SEPARATOR)] = ysKey::Code::Separator;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_DECIMALSEPARATOR)] = ysKey::Code::Decimal;

    // function keys F1 - F23
    for (int i = 0; i < 12; i++) {
        m_keyMap[KEYCODE_TO_SCANCODE(SDLK_F1 + i)] = (ysKey::Code) ((int) ysKey::Code::F1 + i);
        m_keyMap[KEYCODE_TO_SCANCODE(SDLK_F13 + i)] = (ysKey::Code) ((int) ysKey::Code::F13 + i);
    }

    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_NUMLOCKCLEAR)] = ysKey::Code::NumLock;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_SCROLLLOCK)] = ysKey::Code::ScrollLock;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_LALT)] = ysKey::Code::LeftMenu;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_RALT)] = ysKey::Code::RightMenu;

    // browser keys? uhh sure
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_AC_BACK)] = ysKey::Code::BrowserBack;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_AC_FORWARD)] = ysKey::Code::BrowserForward;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_AC_REFRESH)] = ysKey::Code::BrowserRefresh;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_AC_STOP)] = ysKey::Code::BrowserStop;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_AC_SEARCH)] = ysKey::Code::BrowserSearch;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_AC_BOOKMARKS)] = ysKey::Code::BrowserFavorites;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_AC_HOME)] = ysKey::Code::BrowserHome;

    // media keys
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_AUDIOMUTE)] = ysKey::Code::VolumeMute;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_VOLUMEDOWN)] = ysKey::Code::VolumeDown;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_VOLUMEUP)] = ysKey::Code::VolumeUp;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_AUDIONEXT)] = ysKey::Code::MediaNextTrack;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_AUDIOPREV)] = ysKey::Code::MediaPrevTrack;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_AUDIOSTOP)] = ysKey::Code::MediaStop;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_AUDIOPLAY)] = ysKey::Code::MediaPlay;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_MEDIASELECT)] = ysKey::Code::LaunchMediaSelect;
    m_keyMap[KEYCODE_TO_SCANCODE(SDLK_MAIL)] = ysKey::Code::LaunchMail;

    return m_keyMap;
}

#undef KEYCODE_TO_SCANCODE
