#include "yds_al_device.h"

#include "../include/yds_al_audio_buffer.h"
#include "../include/yds_al_audio_source.h"

ysALDevice::ysALDevice() : ysAudioDevice(API::OpenAL) {
    m_device = nullptr;
}

ysALDevice::~ysALDevice() {

}

ysAudioBuffer *ysALDevice::CreateBuffer(const ysAudioParameters *parameters, SampleOffset size) {
    auto *newBuffer = m_audioBuffers.NewGeneric<ysALAudioBuffer>();
    newBuffer->Initialize(size, *parameters);

    return newBuffer;
}

ysAudioSource *ysALDevice::CreateSource(const ysAudioParameters *parameters, SampleOffset size) {
    auto *newSource = m_audioSources.NewGeneric<ysALAudioSource>();
    newSource->m_bufferSize = size;
    newSource->m_audioParameters = *parameters;

    return newSource;
}

ysAudioSource *ysALDevice::CreateSource(ysAudioBuffer *sourceBuffer) {
    ysAudioSource *newSource = CreateSource(sourceBuffer->GetAudioParameters(), sourceBuffer->GetSampleCount());
    newSource->SetDataBuffer(sourceBuffer);

    return newSource;
}

void ysALDevice::UpdateAudioSources() {
    int sourceCount = m_audioSources.GetNumObjects();

    for (int i = sourceCount - 1; i >= 0; --i) {
        ysALAudioSource *alSource = static_cast<ysALAudioSource*>(m_audioSources.Get(i));

        if (alSource->GetBufferMode() == ysAudioSource::Mode::PlayOnce) {
            alSource->m_buffer.
        }
    }

}
