#ifndef FILE_TIME_MONITOR_H
#define FILE_TIME_MONITOR_H

#include "monitor.h"

class FileTimeManager {
    public:
        void monitor(File file, bool shouldDeleteSavedVersions);
};

#endif // FILE_TIME_MONITOR_H
