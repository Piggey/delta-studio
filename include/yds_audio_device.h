#ifndef YDS_AUDIO_DEVICE_H
#define YDS_AUDIO_DEVICE_H

#include "yds_audio_system_object.h"
#include "yds_audio_parameters.h"

#include "yds_window.h"

#if defined(__GNUC__)
    #define __STDC_WANT_LIB_EXT1__ 1
    #include <string.h>
#endif

class ysAudioSource;
class ysAudioBuffer;

class ysAudioDevice : public ysAudioSystemObject {
    friend class ysAudioSystem;

public:
    static constexpr int MaxDeviceNameLength = 256;

public:
    ysAudioDevice();
    ysAudioDevice(API api);
    ~ysAudioDevice();

    bool IsConnected() const { return m_connected; }
    void SetDeviceName(const char *newName) {
#if defined(__GNUC__)
        // since safe versions of these are not really supported in C++ official standards
        // we use the unsafe versions
        // potential weak point?
        strcpy(m_deviceName, newName);
#elif defined(_MSC_VER) 
        strcpy_s(m_deviceName, MaxDeviceNameLength, newName);
#endif
    }

    virtual ysAudioBuffer *CreateBuffer(const ysAudioParameters *parameters, SampleOffset size) = 0;

    virtual ysAudioSource *CreateSource(const ysAudioParameters *parameters, SampleOffset size) = 0;
    virtual ysAudioSource *CreateSource(ysAudioBuffer *sourceBuffer) = 0;

    virtual void UpdateAudioSources() = 0;

    virtual ysError DestroyAudioBuffer(ysAudioBuffer *&buffer);
    virtual ysError DestroyAudioSource(ysAudioSource *&source);
    ysError DestroyAudioBuffers();

protected:
    char m_deviceName[MaxDeviceNameLength];
    ysWindow *m_windowAssociation;

    ysDynamicArray<ysAudioBuffer, 4> m_audioBuffers;
    ysDynamicArray<ysAudioSource, 4> m_audioSources;

    bool m_connected;
};

#endif /* YDS_AUDIO_DEVICE_H */
