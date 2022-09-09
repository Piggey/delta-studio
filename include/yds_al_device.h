#ifndef YDS_AL_DEVICE_H
#define YDS_AL_DEVICE_H

#include "yds_audio_device.h"

#include <AL/alc.h>

class ysALSystem;

class ysALDevice : public ysAudioDevice {
    friend ysALSystem;

public:
    ysALDevice();
    ~ysALDevice() override;

    ysAudioBuffer *CreateBuffer(const ysAudioParameters *parameters, SampleOffset size) override;

    ysAudioSource *CreateSource(const ysAudioParameters *parameters, SampleOffset size) override;
    ysAudioSource *CreateSource(ysAudioBuffer *sourceBuffer) override;

    void UpdateAudioSources() override;

private:
    ALCdevice* m_device;
};


#endif //YDS_AL_DEVICE_H
