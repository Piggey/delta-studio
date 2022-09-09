#include "yds_al_audio_source.h"

ysALAudioSource::ysALAudioSource() : ysAudioSource(API::OpenAL) {
    alGenBuffers(1, &m_buffer);
}

ysALAudioSource::~ysALAudioSource() {

}

ysError ysALAudioSource::LockEntireBuffer(void **buffer, SampleOffset *samples) {
    return ysAudioSource::LockEntireBuffer(buffer, samples);
}

ysError ysALAudioSource::UnlockBuffer(void *buffer, SampleOffset samples) {
    return ysAudioSource::UnlockBuffer(buffer, samples);
}

ysError
ysALAudioSource::LockBufferSegment(SampleOffset offset, SampleOffset samples, void **segment1, SampleOffset *size1,
                                   void **segment2, SampleOffset *size2) {
    return ysAudioSource::LockBufferSegment(offset, samples, segment1, size1, segment2, size2);
}

ysError ysALAudioSource::UnlockBufferSegments(void *segment1, SampleOffset segment1Size, void *segment2,
                                              SampleOffset segment2Size) {
    return ysAudioSource::UnlockBufferSegments(segment1, segment1Size, segment2, segment2Size);
}

ysError ysALAudioSource::SetDataBuffer(ysAudioBuffer *buffer) {
    return ysAudioSource::SetDataBuffer(buffer);
}

ysError ysALAudioSource::SetMode(ysAudioSource::Mode mode) {
    return ysAudioSource::SetMode(mode);
}

SampleOffset ysALAudioSource::GetCurrentPosition() {
    return ysAudioSource::GetCurrentPosition();
}

SampleOffset ysALAudioSource::GetCurrentWritePosition() {
    return ysAudioSource::GetCurrentWritePosition();
}

void ysALAudioSource::Seek(SampleOffset offset) {
    ysAudioSource::Seek(offset);
}

ysError ysALAudioSource::SetVolume(float volume) {
    return ysAudioSource::SetVolume(volume);
}

ysError ysALAudioSource::SetPan(float pan) {
    return ysAudioSource::SetPan(pan);
}

ysError ysALAudioSource::Destroy() {
    return ysAudioSource::Destroy();
}
