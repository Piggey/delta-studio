#ifndef YDS_AL_AUDIO_SOURCE_H
#define YDS_AL_AUDIO_SOURCE_H

#include "yds_audio_source.h"

#include <AL/al.h>
#include <AL/alc.h>

class ysALDevice;

class ysALAudioSource : public ysAudioSource {
    friend ysALDevice;

public:
    ysALAudioSource();
    ~ysALAudioSource() override;

    ysError LockEntireBuffer(void **buffer, SampleOffset *samples) override;
    ysError UnlockBuffer(void *buffer, SampleOffset samples) override;

    ysError LockBufferSegment(SampleOffset offset, SampleOffset samples, void **segment1, SampleOffset *size1, void **segment2, SampleOffset *size2) override;
    ysError UnlockBufferSegments(void *segment1, SampleOffset segment1Size, void *segment2, SampleOffset segment2Size) override;

    ysError SetMode(Mode mode) override;

    ysError SetDataBuffer(ysAudioBuffer *buffer) override;

    ysError SetVolume(float volume) override;
    ysError SetPan(float pan) override;

    SampleOffset GetCurrentPosition() override;
    SampleOffset GetCurrentWritePosition() override;

    void Seek(SampleOffset offset) override;

    ysError Destroy() override;

protected:
    ALuint m_buffer;
};


#endif //YDS_AL_AUDIO_SOURCE_H
