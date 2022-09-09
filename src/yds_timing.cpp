#include "../include/yds_timing.h"

#if defined(_MSC_VER)
    #include <windows.h>
    #include <mmsystem.h>
    #include <intrin.h>
#elif defined(__GNUC__)
    #include <chrono>
    #define LARGE_INTEGER int64_t // sure whatever
#endif

static bool qpcFlag;
static LARGE_INTEGER qpcFrequency;

ysTimingSystem *ysTimingSystem::g_instance = nullptr;

uint64_t SystemTime() {
#if defined(__GNUC__)
    // QueryPerformanceCounter will just not work on linux kernel. This is a workaround?
    // https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/6/html/power_management_guide/tickless-kernel

    // we'll just return time in microseconds
    auto now = std::chrono::system_clock::now();
    return (uint64_t) (std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count());
#elif defined(_MSC_VER)
    if (qpcFlag) {
        LARGE_INTEGER currentTime;
        QueryPerformanceCounter(&currentTime);

        currentTime.QuadPart *= 1000000;
        currentTime.QuadPart /= qpcFrequency.QuadPart;

        return (uint64_t)(currentTime.QuadPart);
    }
    else {
        // Convert output to microseconds
        return (uint64_t)(timeGetTime() * 1000);
    }
#endif
}

ysTimingSystem::ysTimingSystem() {
    SetPrecisionMode(Precision::Microsecond);
    Initialize();
}

ysTimingSystem::~ysTimingSystem() {
    /* void */
}

uint64_t ysTimingSystem::GetTime() {
    return SystemTime();
}

inline uint64_t SystemClock() {
#if defined(_MSC_VER)
    return __rdtsc();
#else
    return SystemTime();
#endif
}

uint64_t ysTimingSystem::GetClock() {
    return (uint64_t) SystemClock();
}

void ysTimingSystem::SetPrecisionMode(Precision mode) {
    m_precisionMode = mode;

    if (mode == Precision::Millisecond) {
        m_div = 1000.0;
    }
    else if (mode == Precision::Microsecond) {
        m_div = 1000000.0;
    }
}

double ysTimingSystem::ConvertToSeconds(uint64_t t_u) const {
    return t_u / m_div;
}

void ysTimingSystem::Update() {
    if (!m_isPaused) {
        m_frameNumber++;
    }

    uint64_t thisTime = GetTime();
    m_lastFrameDuration = (thisTime - m_lastFrameTimestamp);
    m_lastFrameTimestamp = thisTime;

    uint64_t thisClock = GetClock();
    m_lastFrameClockTicks = (thisClock - m_lastFrameClockstamp);
    m_lastFrameClockstamp = thisClock;

    if (m_frameNumber > 1) {
        if (m_averageFrameDuration <= 0) {
            m_averageFrameDuration = (double)(m_lastFrameDuration / m_div);
        }
        else {
            m_averageFrameDuration *= 0.95;
            m_averageFrameDuration += 0.05 * (double)m_lastFrameDuration / m_div;

            m_fps = (float)(1 / m_averageFrameDuration);
        }
    }
}

void ysTimingSystem::Initialize() {
#if defined(_MSC_VER)
    qpcFlag = (QueryPerformanceFrequency(&qpcFrequency) > 0);
#elif defined(__GNUC__)
    qpcFlag = false;
#endif

    m_frameNumber = 0;

    m_lastFrameTimestamp = GetTime();
    m_lastFrameDuration = 0;

    m_lastFrameClockstamp = GetClock();
    m_lastFrameClockTicks = 0;

    m_isPaused = false;

    m_averageFrameDuration = 0;
    m_fps = 0;
}

double ysTimingSystem::GetFrameDuration() const {
    return m_lastFrameDuration / m_div;
}

uint64_t ysTimingSystem::GetFrameDuration_us() const {
    return m_lastFrameDuration;
}
