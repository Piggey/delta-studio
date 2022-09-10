#ifndef YDS_UNIX_INPUT_DEVICE_H
#define YDS_UNIX_INPUT_DEVICE_H

#include "yds_input_device.h"

#include <SDL2/SDL_hidapi.h>

class ysUnixInputDevice : public ysInputDevice {
    friend class ysUnixInputSystem;

public:
    ysUnixInputDevice();
    explicit ysUnixInputDevice(InputDeviceType type);
    ~ysUnixInputDevice() override;

private:
    SDL_hid_device* m_device;
    unsigned short m_vendorID;
    unsigned short m_productID;
};

#endif //YDS_UNIX_INPUT_DEVICE_H
