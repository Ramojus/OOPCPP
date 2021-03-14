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
            int ID;
            static const unsigned int MINUTES_PER_HOUR;
            static const unsigned int SECONDS_PER_MINUTE;
            static const char seperator;
            static unsigned int instanceCount;

        public:
            Time();
            Time(int hours, int minutes, int seconds);
            ~Time();
            int getHours() const;
            int getMinutes() const;
            int getSeconds() const;
            std::string getTime() const;
            int getID() const;
            void add(const Time &time);
            void subtract(const Time &time);
            void fixFormat();
            std::string toString() const;
            friend std::ostream& operator<<(std::ostream &outputStream, const Time &time);
            // reads input in H:M:S format with strong exception safety guarantee
            friend std::istream& operator>>(std::istream &inputStream, Time &time);
            bool operator==(const Time &time) const;
            bool operator!=(const Time &time) const;
            bool operator>(const Time &time) const;
            bool operator>=(const Time &time) const;
            bool operator<(const Time &time) const;
            bool operator<=(const Time &time) const;
            // adds one minute
            Time operator++();
            Time operator++(int);
            // subtracts one minute
            Time operator--();
            Time operator--(int);
    };
};

#endif // __TIME_H
