#ifndef YDS_VULKAN_H
#define YDS_VULKAN_H

#include <vulkan/vulkan_core.h>
#if defined(_MSC_VER)
    #include <Windows.h>
    #include <vulkan/vulkan_win32.h>
#elif defined(__GNUC__)
    #include <vulkan/vulkan_core.h>

#endif


#endif /* YDS_VULKAN_H */
