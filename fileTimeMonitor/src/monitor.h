#ifndef MONITOR_H
#define MONITOR_H

#include "file.h"

class Monitor {
    private:
        File file;
    public:
        Monitor(File file);
        void start();
        void stop();
};

#endif // MONITOR_H
