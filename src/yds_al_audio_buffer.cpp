#include "../include/yds_al_audio_buffer.h"

ysALAudioBuffer::ysALAudioBuffer() : ysAudioBuffer(API::OpenAL) {
    m_buffer = nullptr;
}

ysALAudioBuffer::~ysALAudioBuffer() {

}

ysError ysALAudioBuffer::Initialize(SampleOffset samples, const ysAudioParameters &parameters) {
    return ysAudioBuffer::Initialize(samples, parameters);
}

ysError ysALAudioBuffer::EditBuffer(void *data) {
    return ysAudioBuffer::EditBuffer(data);
}

ysError ysALAudioBuffer::EditBufferSegment(void *data, SampleOffset samples, SampleOffset offset) {
    return ysAudioBuffer::EditBufferSegment(data, samples, offset);
}

ysError ysALAudioBuffer::Destroy() {
    return ysAudioBuffer::Destroy();
}
