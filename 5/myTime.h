#ifndef __TIME_H
#define __TIME_H

#include <iostream>
#include <sstream>

namespace My {
    class Time {
        private:
            class Private;
            Private *p; 

        public:
            Time();
            Time(const Time &time);
            Time(int hours, int minutes, int seconds);
            ~Time();

            int getHours() const;
            int getMinutes() const;
            int getSeconds() const;
            std::string getTime() const;
            int getID() const;

            void add(const Time &time);
            void subtract(const Time &time);
            std::string toString() const;

            friend std::ostream& operator<<(std::ostream &outputStream, const Time &time);
            // reads input in H:M:S format with strong exception safety guarantee
            friend std::istream& operator>>(std::istream &inputStream, Time &time);

            bool operator==(const Time &time) const;
            bool operator!=(const Time &time) const;
            bool operator<(const Time &time) const;
            bool operator<=(const Time &time) const;
            bool operator>(const Time &time) const;
            bool operator>=(const Time &time) const;

            Time& operator=(Time time);

            // operates on minutes
            Time operator++();
            // operates on minutes
            Time operator++(int);
            // operates on minutes
            Time operator--();
            // operates on minutes
            Time operator--(int);
            
            friend class Private;
    };
};

#endif // __TIME_H
