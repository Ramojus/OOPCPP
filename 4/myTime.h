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
            static const unsigned int MINUTES_PER_HOUR;
            static const unsigned int SECONDS_PER_MINUTE;
            static const char seperator;
            static unsigned int instanceCount;
            int ID;

        public:
            Time();
            Time(int hours, int minutes, int seconds);
            ~Time();
            int getHours();
            int getMinutes();
            int getSeconds();
            std::string getTime() const;
            int getID();
            void add(Time time);
            void subtract(Time time);
            void fixFormat();
            std::string toString();
            friend std::ostream& operator<<(std::ostream &outputStream, const Time &time);
            friend std::istream& operator>>(std::istream &inputStream, Time &time);
            bool operator==(const Time &time) const;
            bool operator!=(const Time &time) const;
            bool operator>(const Time &time) const;
            bool operator>=(const Time &time) const;
            bool operator<(const Time &time) const;
            bool operator<=(const Time &time) const;
            Time &operator++();
            Time operator++(int);
            Time &operator--();
            Time operator--(int);
    };
};

#endif // __TIME_H
