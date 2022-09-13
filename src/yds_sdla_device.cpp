#include "../include/yds_sdla_device.h"

#include "../include/yds_sdla_audio_buffer.h"
#include "../include/yds_sdla_audio_source.h"

ysSDLADevice::ysSDLADevice() : ysAudioDevice(API::SDLAudio) {
    m_sdlaDevID = 0;
}

ysSDLADevice::~ysSDLADevice() {

}

ysAudioBuffer *ysSDLADevice::CreateBuffer(const ysAudioParameters *parameters, SampleOffset size) {
    auto *newBuffer = m_audioBuffers.NewGeneric<ysSDLAAudioBuffer>();
    newBuffer->Initialize(size, *parameters);

    return newBuffer;
}

ysAudioSource *ysSDLADevice::CreateSource(const ysAudioParameters *parameters, SampleOffset size) {
    auto *newSource = m_audioSources.NewGeneric<ysSDLAAudioSource>();
    newSource->m_bufferSize = size;
    newSource->m_audioParameters = *parameters;

    m_sdlAudioSpec.freq = parameters->m_sampleRate;
    m_sdlAudioSpec.format = AUDIO_F32;
    m_sdlAudioSpec.channels = parameters->m_channelCount;
    m_sdlAudioSpec.samples = parameters->GetSamplesFromSize(size);

    return newSource;
}

ysAudioSource *ysSDLADevice::CreateSource(ysAudioBuffer *sourceBuffer) {
    auto *newSource = CreateSource(sourceBuffer->GetAudioParameters(), sourceBuffer->GetSampleCount());
    newSource->SetDataBuffer(sourceBuffer);

    return newSource;
}

void ysSDLADevice::UpdateAudioSources() {
    const int sourceCount = m_audioSources.GetNumObjects();
    for (int i = sourceCount - 1; i >= 0; --i) {
        auto *sdlaSource = dynamic_cast<ysSDLAAudioSource*>(m_audioSources.Get(i));
        SDL_AudioStatus deviceStatus = SDL_GetAudioDeviceStatus(m_sdlaDevID);

        if (sdlaSource->GetBufferMode() == ysAudioSource::Mode::PlayOnce &&
            deviceStatus != SDL_AUDIO_PLAYING) {

            sdlaSource->Destroy();
            m_audioBuffers.Delete(sdlaSource->GetIndex()); // we're deleting the buffer???
        }
    }
}
