#include "../include/os_utilities.h"

#include "../include/path.h"

#if defined(_MSC_VER)
    #include <Windows.h>
#elif defined(__GNUC__)
    #include <unistd.h>
#endif

dbasic::Path dbasic::GetModulePath() {
    char path[256];

#if defined(_MSC_VER)
    DWORD result = GetModuleFileName(NULL, path, 256);

    Path fullPath = Path(path);
    Path parentPath;

    fullPath.GetParentPath(&parentPath);

#elif defined(__GNUC__)
    char id[256];
    sprintf(id, "/proc/%d/exe", getpid());
    readlink(id, path, 255);
    path[255] = '\0';

    Path fullPath = Path(path);
    Path parentPath;
    fullPath.GetParentPath(&parentPath);

#endif

    return parentPath;
}
