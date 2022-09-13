#ifndef YDS_SDLA_DEVICE_H
#define YDS_SDLA_DEVICE_H

#include "yds_audio_device.h"

#include <SDL2/SDL_audio.h>

class ysSDLADevice : public ysAudioDevice {
    friend class ysSDLASystem;

public:
    ysSDLADevice();
    ~ysSDLADevice() override;

    ysAudioBuffer *CreateBuffer(const ysAudioParameters *parameters, SampleOffset size) override;

    ysAudioSource *CreateSource(const ysAudioParameters *parameters, SampleOffset size) override;
    ysAudioSource *CreateSource(ysAudioBuffer *sourceBuffer) override;

    void UpdateAudioSources() override;

protected:
    SDL_AudioDeviceID m_sdlaDevID;
    SDL_AudioSpec m_sdlAudioSpec{};
};


#endif //YDS_SDLA_DEVICE_H
