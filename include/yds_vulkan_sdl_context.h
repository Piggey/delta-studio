#ifndef YDS_VULKAN_SDL_CONTEXT_H
#define YDS_VULKAN_SDL_CONTEXT_H

#include "yds_vulkan_context.h"

#include "vulkan/vulkan.h"

class ysVulkanDevice;

class ysVulkanSdlContext : public ysVulkanContext {
    friend ysVulkanDevice;
public:
    ysVulkanSdlContext();
    ~ysVulkanSdlContext() override;

    void SetDebugName(const std::string &debugName) override;

    ysError Create(ysVulkanDevice *device, ysWindow *window) override;

    ysError Destroy() override;
};


#endif //YDS_VULKAN_SDL_CONTEXT_H
