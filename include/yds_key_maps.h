#ifndef YDS_KEY_MAPS_H
#define YDS_KEY_MAPS_H

#include "yds_keyboard.h"

class ysKeyMaps {
public:
    ysKeyMaps() { m_keyMap = nullptr; }
    ~ysKeyMaps() {}

    static const ysKey::Code *GetWindowsKeyMap();

protected:
    static ysKey::Code *m_keyMap;
};

#endif /* YDS_KEY_MAPS_H */
