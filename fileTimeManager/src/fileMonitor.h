#ifndef FILE_MONITOR_H
#define FILE_MONITOR_H

#include <iostream>
#include <ctime>

#include "file.h"

class FileMonitor {
    private:
        File file;
    public:
        FileMonitor(File file);
        ~FileMonitor();
        void start();
        void stop();
};

#endif // FILE_MONITOR_H
