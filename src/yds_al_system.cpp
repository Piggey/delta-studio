#include "yds_al_system.h"

ysALSystem::ysALSystem() : ysAudioSystem(API::OpenAL) {

}

ysALSystem::~ysALSystem() {

}

void ysALSystem::EnumerateDevices() {
    ysAudioSystem::EnumerateDevices();

    // to get a list of all available audio devices
    alcGetString(nullptr, ALC_DEVICE_SPECIFIER);
}

void ysALSystem::ConnectDevice(ysAudioDevice *device, ysWindow *windowAssociation) {
    ysAudioSystem::ConnectDevice(device, windowAssociation);

    ysALDevice* alDevice = static_cast<ysALDevice*>(device);

    alcOpenDevice(device->m_device)
}

void ysALSystem::ConnectDeviceConsole(ysAudioDevice *device) {
    ysAudioSystem::ConnectDeviceConsole(device);
}

void ysALSystem::DisconnectDevice(ysAudioDevice *device) {
    ysAudioSystem::DisconnectDevice(device);
}
