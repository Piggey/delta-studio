#include "../include/yds_sdla_audio_buffer.h"

ysSDLAAudioBuffer::ysSDLAAudioBuffer() : ysAudioBuffer(API::SDLAudio) {
    m_buffer = nullptr;
}

ysSDLAAudioBuffer::~ysSDLAAudioBuffer() {

}

ysError ysSDLAAudioBuffer::Initialize(const SampleOffset& samples, const ysAudioParameters &parameters) {
    YDS_ERROR_DECLARE("Initialize");

    YDS_NESTED_ERROR_CALL(ysAudioBuffer::Initialize(samples, parameters));

    m_buffer = malloc(parameters.GetSizeFromSamples(samples));
    if (m_buffer != nullptr) {
        memset(m_buffer, 0, parameters.GetSizeFromSamples(samples));
        return YDS_ERROR_RETURN(ysError::None);
    }
    else {
        return YDS_ERROR_RETURN(ysError::OutOfMemory);
    }
}

ysError ysSDLAAudioBuffer::EditBuffer(const void *data) {
    YDS_ERROR_DECLARE("EditBuffer");

    memcpy(m_buffer, data, m_audioParameters.GetSizeFromSamples(m_samples));

    return YDS_ERROR_RETURN(ysError::None);
}

ysError ysSDLAAudioBuffer::EditBufferSegment(void *data, const SampleOffset &samples, const SampleOffset &offset) {
    YDS_ERROR_DECLARE("EditBufferSegment");

    size_t offsetBytes = m_audioParameters.GetSizeFromSamples(offset);
    memcpy((char*) data + offsetBytes, data, samples);

    return YDS_ERROR_RETURN(ysError::None);
}

ysError ysSDLAAudioBuffer::Destroy() {
    YDS_ERROR_DECLARE("Destroy");

    free(m_buffer);

    return YDS_ERROR_RETURN(ysError::None);
}
