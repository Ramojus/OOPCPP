#ifndef CURRENT_TIMESTAMP_H
#define CURRENT_TIMESTAMP_H

#include <ctime>

class CurrentTimestamp {
    private:
        static time_t timestamp;
    public:
        static void setTimestamp(time_t timestamp);
        static time_t getTimestamp();
};

#endif // CURRENT_TIMESTAMP_H
