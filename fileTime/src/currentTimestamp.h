#ifndef __CURRENT_TIMESTAMP_H
#define __CURRENT_TIMESTAMP_H

#include <iostream>
#include <ctime>

class CurrentTimestamp {
    private:
        static time_t timestamp;
    public:
        static time_t getTimestamp();
        static void setTimestamp();
};

#endif // __CURRENT_TIMESTAMP_H
