#include "../include/yds_sdla_audio_source.h"

#include "../include/yds_sdla_audio_buffer.h"

ysSDLAAudioSource::ysSDLAAudioSource() : ysAudioSource(API::SDLAudio) {

}

ysSDLAAudioSource::~ysSDLAAudioSource() {

}

ysError ysSDLAAudioSource::LockEntireBuffer(void **buffer, SampleOffset *samples) {
    YDS_ERROR_DECLARE("LockEntireBuffer");
    YDS_NESTED_ERROR_CALL(ysAudioSource::LockEntireBuffer(buffer, samples));

}

ysError ysSDLAAudioSource::UnlockBuffer(void *buffer, SampleOffset samples) {
    return ysAudioSource::UnlockBuffer(buffer, samples);
}

ysError
ysSDLAAudioSource::LockBufferSegment(SampleOffset offset, SampleOffset samples, void **segment1, SampleOffset *size1,
                                     void **segment2, SampleOffset *size2) {
    return ysAudioSource::LockBufferSegment(offset, samples, segment1, size1, segment2, size2);
}

ysError ysSDLAAudioSource::UnlockBufferSegments(void *segment1, SampleOffset segment1Size, void *segment2,
                                                SampleOffset segment2Size) {
    return ysAudioSource::UnlockBufferSegments(segment1, segment1Size, segment2, segment2Size);
}

ysError ysSDLAAudioSource::SetDataBuffer(ysAudioBuffer *buffer) {
    return ysAudioSource::SetDataBuffer(buffer);
}

ysError ysSDLAAudioSource::SetMode(ysAudioSource::Mode mode) {
    return ysAudioSource::SetMode(mode);
}

SampleOffset ysSDLAAudioSource::GetCurrentPosition() {
    return ysAudioSource::GetCurrentPosition();
}

SampleOffset ysSDLAAudioSource::GetCurrentWritePosition() {
    return ysAudioSource::GetCurrentWritePosition();
}

void ysSDLAAudioSource::Seek(SampleOffset offset) {
    ysAudioSource::Seek(offset);
}

ysError ysSDLAAudioSource::SetVolume(float volume) {
    return ysAudioSource::SetVolume(volume);
}

ysError ysSDLAAudioSource::SetPan(float pan) {
    return ysAudioSource::SetPan(pan);
}

ysError ysSDLAAudioSource::Destroy() {
    return ysAudioSource::Destroy();
}
