#ifndef __TIME_H
#define __TIME_H

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
            static void setMinutesPerHour(unsigned int minutesPerHour);
            static void setSecondsPerMinute(unsigned int secondsPerMinute);
            int getHours();
            int getMinutes();
            int getSeconds();
            int getID();
            void add(Time time);
            void subtract(Time time);
            void fixFormat();
            std::string toString();
        private:
            int getNrOfDigits(int value);
            std::string getCountDigits(int count, int value);

        public:
            bool operator==(const Time &time) const;
            bool operator!=(const Time &time) const;
            bool operator>(const Time &time) const;
            bool operator<(const Time &time) const;
            bool operator>=(const Time &time) const;
            bool operator<=(const Time &time) const;
    };
};

#endif // __TIME_H
