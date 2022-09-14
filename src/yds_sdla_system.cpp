#include "../include/yds_sdla_system.h"

#include "../include/yds_sdla_device.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

ysSDLASystem::ysSDLASystem() : ysAudioSystem(API::SDLAudio) {
    if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
        fprintf(stderr, "Failed initializing audio.\n%s\n", SDL_GetError());
    }
}

ysSDLASystem::~ysSDLASystem() {
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}

void ysSDLASystem::EnumerateDevices() {
    ysAudioSystem::EnumerateDevices();

    const int numDevices = SDL_GetNumAudioDevices(0);
    for (int i = 0; i < numDevices; i++) {
        auto *audioDevice = m_devices.NewGeneric<ysSDLADevice>();

        audioDevice->m_index = i;
        strcpy(audioDevice->m_deviceName, SDL_GetAudioDeviceName(i, 0));
    }
}

void ysSDLASystem::ConnectDevice(ysAudioDevice *device, ysWindow *windowAssociation) {
    ysAudioSystem::ConnectDevice(device, windowAssociation);

    auto *sdlaDevice = dynamic_cast<ysSDLADevice*>(device);
    sdlaDevice->m_sdlDeviceID = SDL_OpenAudioDevice(
            sdlaDevice->m_deviceName,
            0,
            &sdlaDevice->m_sdlAudioSpec,
            &sdlaDevice->m_sdlAudioSpec, // BAD!
            SDL_AUDIO_ALLOW_FORMAT_CHANGE
    );
}

void ysSDLASystem::ConnectDeviceConsole(ysAudioDevice *device) {
    ConnectDevice(device, nullptr);
}

void ysSDLASystem::DisconnectDevice(ysAudioDevice *device) {
    ysAudioSystem::DisconnectDevice(device);

    auto *sdlaDevice = dynamic_cast<ysSDLADevice*>(device);
    SDL_CloseAudioDevice(sdlaDevice->m_sdlDeviceID);
}
