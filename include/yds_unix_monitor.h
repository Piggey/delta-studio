#ifndef YDS_UNIX_MONITOR_H
#define YDS_UNIX_MONITOR_H

#include "yds_monitor.h"

class ysUnixMonitor : public ysMonitor {
public:
    ysUnixMonitor();
    ~ysUnixMonitor() override;
};


#endif //YDS_UNIX_MONITOR_H
