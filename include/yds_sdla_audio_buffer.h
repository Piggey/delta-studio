#ifndef YDS_SDLA_AUDIO_BUFFER_H
#define YDS_SDLA_AUDIO_BUFFER_H

#include "yds_audio_buffer.h"

class ysSDLAAudioBuffer : public ysAudioBuffer {
public:
   ysSDLAAudioBuffer();
    ~ysSDLAAudioBuffer() override;

    ysError Initialize(const SampleOffset &samples, const ysAudioParameters &parameters) override;
    ysError EditBuffer(const void *data) override;
    ysError EditBufferSegment(void *data, const SampleOffset &samples, const SampleOffset &offset) override;
    ysError Destroy() override;

    void *GetBuffer() const { return m_buffer; }

protected:
    void *m_buffer;
};

#endif //YDS_SDLA_AUDIO_BUFFER_H
