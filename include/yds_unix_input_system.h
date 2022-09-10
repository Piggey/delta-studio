#ifndef YDS_UNIX_INPUT_SYSTEM_H
#define YDS_UNIX_INPUT_SYSTEM_H

#include "yds_input_system.h"

class ysUnixInputSystem : public ysInputSystem {
public:
    ysUnixInputSystem();
    ~ysUnixInputSystem() override;

    ysError CheckDeviceStatus(ysInputDevice *device) override;
    ysError CheckAllDevices() override;

protected:
    ysInputDevice *CreateDevice(ysInputDevice::InputDeviceType type, int id) override;
    ysError CreateDevices() override;
};


#endif //YDS_UNIX_INPUT_SYSTEM_H
