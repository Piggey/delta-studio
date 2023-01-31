#include "../include/yds_vulkan_sdl_context.h"

#include "../include/yds_sdl_window.h"

ysVulkanSdlContext::ysVulkanSdlContext() : ysVulkanContext(ysWindowSystem::Platform::Sdl) {
    m_device = nullptr;
}

ysVulkanSdlContext::~ysVulkanSdlContext() {

}

void ysVulkanSdlContext::SetDebugName(const std::string &debugName) {
    ysContextObject::SetDebugName(debugName);
}

ysError ysVulkanSdlContext::Create(ysVulkanDevice *device, ysWindow *window) {
    YDS_ERROR_DECLARE("CreateRenderingContext");

    if (window->GetPlatform() != ysWindowSystemObject::Platform::Sdl) {
        return YDS_ERROR_RETURN(ysError::IncompatiblePlatforms);
    }

    auto *sdlWindow = static_cast<ysSdlWindow *>(window);

}

ysError ysVulkanSdlContext::Destroy() {
    return ysError::TestError;
}
