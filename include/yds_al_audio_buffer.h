#ifndef YDS_AL_AUDIO_BUFFER_H
#define YDS_AL_AUDIO_BUFFER_H

#include "yds_audio_buffer.h"

class ysALAudioBuffer : public ysAudioBuffer {
public:
    ysALAudioBuffer();
    ~ysALAudioBuffer() override;

    ysError Initialize(SampleOffset samples, const ysAudioParameters &parameters) override;
    ysError EditBuffer(void *data) override;
    ysError EditBufferSegment(void *data, SampleOffset samples, SampleOffset offset) override;
    ysError Destroy() override;

    void *GetBuffer() const { return m_buffer; }

protected:
    void *m_buffer;
};


#endif //YDS_AL_AUDIO_BUFFER_H
