#ifndef YDS_UNIX_DEFS_H
#define YDS_UNIX_DEFS_H

#if defined(__GNUC__)
    #ifndef __forceinline
        // since actually forcing to be inline produced many warnings
        #define __forceinline inline
    #endif

    #if !defined(_aligned_malloc) && !defined(_aligned_free)
        #include <cstdlib>
        #define _aligned_malloc(size, alignment) aligned_alloc(alignment, size)
        #define _aligned_free free
    #endif


    #ifndef strcpy_s
        #include <cstring>
        // strncpy does not create null byte if source is longer than dest, so we do it manually just in case
        #define strcpy_s(dest, maxSize, source) do {    \
            strncpy(dest, source, maxSize);             \
            if (strlen(source) > maxSize)               \
                dest[maxSize - 1] = '\0';               \
        } while(false);
    #endif

    #ifndef strcat_s
        #include <cstring>
        // same thing as strncpy
        #define strcat_s(dest, size, source) do {   \
            strncat(dest, source, size);            \
            dest[size - 1] = '\0';                  \
        } while(false);
    #endif

    #ifndef sprintf_s
        #include <cstdio>
        #define sprintf_s(buffer, size, format, ...) do {   \
            snprintf(buffer, size, format, __VA_ARGS__);    \
        } while(false);
    #endif

    #ifndef fopen_s
        #include <cstdio>
        #define fopen_s(pFile, filename, mode) do { \
            *pFile = fopen(filename, mode);         \
        } while(false);
    #endif

    #ifndef localtime_s
        #include <ctime>
        #define localtime_s(tstruct, timet) do { \
            localtime_r(timet, tstruct);         \
        } while(false);
    #endif
#endif 

#endif /* YDS_UNIX_DEFS_H */