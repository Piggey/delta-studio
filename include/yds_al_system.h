#ifndef YDS_ALC_SYSTEM_H
#define YDS_ALC_SYSTEM_H

#include "yds_audio_system.h"
#include "yds_window.h"

#include <AL/al.h>
#include <AL/alc.h>

class ysALDevice;

class ysALSystem : public ysAudioSystem {
public:
    ysALSystem();
    ~ysALSystem() override;

    void EnumerateDevices() override;
    void ConnectDevice(ysAudioDevice *device, ysWindow *windowAssociation) override;
    void ConnectDeviceConsole(ysAudioDevice *device) override;
    void DisconnectDevice(ysAudioDevice *device) override;

protected:
    ysALDevice* AddALDevice();
};

#endif //YDS_ALC_SYSTEM_H
