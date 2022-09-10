#include "../include/yds_unix_input_system.h"

#include "../include/yds_unix_input_device.h"
#include "../include/yds_key_maps.h"

#include <SDL2/SDL_hidapi.h>

ysUnixInputSystem::ysUnixInputSystem() : ysInputSystem(Platform::Linux) {

}

ysUnixInputSystem::~ysUnixInputSystem() {

}

ysError ysUnixInputSystem::CheckDeviceStatus(ysInputDevice *device) {
    YDS_ERROR_DECLARE("CheckDeviceStatus");

    if (device == nullptr)
        return YDS_ERROR_RETURN(ysError::InvalidParameter);

    auto *unixDevice = dynamic_cast<ysUnixInputDevice*>(device);
    auto* deviceInfoList = SDL_hid_enumerate(unixDevice->m_vendorID, unixDevice->m_productID);

    if (deviceInfoList == nullptr) {
        return YDS_ERROR_RETURN(ysError::NoDeviceList);
    }

    auto* temp = deviceInfoList;
    while (temp->next != nullptr) {



        temp = temp->next;
    }
}

ysError ysUnixInputSystem::CheckAllDevices() {
    return ysInputSystem::CheckAllDevices();
}

ysError ysUnixInputSystem::CreateDevices() {
    YDS_ERROR_DECLARE("CreateDevices");

    CreateDevice(ysInputDevice::InputDeviceType::KEYBOARD, 0);
    CreateDevice(ysInputDevice::InputDeviceType::MOUSE, 0);

    return YDS_ERROR_RETURN(ysError::None);
}

ysInputDevice *ysUnixInputSystem::CreateDevice(ysInputDevice::InputDeviceType type, int id) {
    const char *baseName;
    char deviceName[ysInputDevice::MAX_NAME_LENGTH];

    switch (type) {
        case ysInputDevice::InputDeviceType::CUSTOM:
            baseName = "HID";
            break;
        case ysInputDevice::InputDeviceType::KEYBOARD:
            baseName = "KEYBOARD";
            break;
        case ysInputDevice::InputDeviceType::MOUSE:
            baseName = "MOUSE";
            break;
        default:
            baseName = "";
    }

    int deviceID;
    if (id >= 0)
        deviceID = id;
    else
        deviceID = GetNextDeviceID(type);

    auto* newDevice = m_inputDeviceArray.NewGeneric<ysUnixInputDevice>();
    sprintf_s(deviceName, 256, "%s%0.3d", baseName, deviceID);

    newDevice->SetName(deviceName);
    newDevice->SetType(type);
    newDevice->SetDeviceID(deviceID);
    newDevice->SetGeneric(true);

    if (type == ysInputDevice::InputDeviceType::KEYBOARD) {
        ysKeyboard *keyboard = newDevice->GetAsKeyboard();
        keyboard->RegisterKeyMap(ysKeyMaps::GetUnixKeyMap());
    }

    RegisterDevice(newDevice);
    return newDevice;
}
