#include "../include/yds_unix_input_device.h"

ysUnixInputDevice::ysUnixInputDevice() : ysInputDevice(Platform::Linux, InputDeviceType::UNKNOWN) {

}

ysUnixInputDevice::ysUnixInputDevice(ysInputDevice::InputDeviceType type)
    : ysInputDevice(Platform::Linux, type) {

}

ysUnixInputDevice::~ysUnixInputDevice() {

}
