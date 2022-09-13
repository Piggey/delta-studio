#include "../include/yds_audio_buffer.h"

ysAudioBuffer::ysAudioBuffer(ysAudioSystemObject::API api) : ysAudioSystemObject("ysAudioBuffer", api) {
    m_samples = 0;
}

ysAudioBuffer::~ysAudioBuffer() {
    /* void */
}

ysError ysAudioBuffer::Initialize(const SampleOffset &samples, const ysAudioParameters &parameters) {
    YDS_ERROR_DECLARE("Initialize");

    m_audioParameters = parameters;
    m_samples = samples;

    return YDS_ERROR_RETURN(ysError::None);
}

ysError ysAudioBuffer::EditBuffer(const void *data) {
    YDS_ERROR_DECLARE("EditBuffer");

    return YDS_ERROR_RETURN(ysError::None);
}

ysError ysAudioBuffer::EditBufferSegment(void *data, const SampleOffset &samples, const SampleOffset &offset) {
    YDS_ERROR_DECLARE("EditBufferSegment");

    return YDS_ERROR_RETURN(ysError::None);
}

ysError ysAudioBuffer::Destroy() {
    YDS_ERROR_DECLARE("Destroy");

    return YDS_ERROR_RETURN(ysError::None);
}
