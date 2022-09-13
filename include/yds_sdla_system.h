#ifndef YDS_SDLA_SYSTEM_H
#define YDS_SDLA_SYSTEM_H

#include "yds_audio_system.h"
#include "yds_window.h"

class ysSDLASystem : public ysAudioSystem {
public:
    ysSDLASystem();
    ~ysSDLASystem() override;

    void EnumerateDevices() override;

    void ConnectDevice(ysAudioDevice *device, ysWindow *windowAssociation) override;
    void ConnectDeviceConsole(ysAudioDevice *device) override;

    void DisconnectDevice(ysAudioDevice *device) override;
};

#endif //YDS_SDLA_SYSTEM_H
