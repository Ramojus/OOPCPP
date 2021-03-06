//#ifndef __TIME_H
//#define __TIME_H

#include <iostream>
#include <sstream>

namespace My {
    class Time {
        private:
            int hours;
            int minutes;
            int seconds;
            static unsigned int minutesPerHour;
            static unsigned int secondsPerMinute;
            static unsigned int instanceCount;
            const int ID;

        public:
            Time();
            Time(int hours, int minutes, int seconds);
            ~Time();
            static void setMinutesPerHour(int minutesPerHour);
            static void setSecondsPerMinute(int secondsPerMinute);
            int getHours();
            int getMinutes();
            int getSeconds();
            int getID();
            void add(Time time);
            void subtract(Time time);
            void fixFormat();
            std::string toString();
        private:
            std::string getMin2digits(int value);
    };
};

//#endif // __TIME_H
