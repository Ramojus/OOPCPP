#include <iostream>
#include <sstream>
#include <cstring>
#include "myTime.h"

namespace Error {
    namespace Time {
        const std::string wrongInputFormat = "Wrong input format. Should be 'H:M:S'";
    }
}

namespace My {
    class Time::Private {
        int hours;
        int minutes;
        int seconds;
        int ID;
        static const unsigned int MINUTES_PER_HOUR;
        static const unsigned int SECONDS_PER_MINUTE;
        static const char SEPERATOR;
        static unsigned int instanceCount;

        Private() : ID(instanceCount) {
            this->hours = 0;
            this->minutes = 0;
            this->seconds = 0;
        }

        Private(int hours, int minutes, int seconds) : ID(instanceCount) {
            ++this->instanceCount;
            this->hours = hours;
            this->minutes = minutes;
            this->seconds = seconds;
            this->fixFormat();
        }

        void fixFormat() {
            if (this->seconds >= 0) {
                this->minutes += this->seconds / SECONDS_PER_MINUTE;
                this->seconds = this->seconds % SECONDS_PER_MINUTE;
            }
            else if (this->minutes > 0) {
                this->minutes -= (-this->seconds) / SECONDS_PER_MINUTE + 1;
                this->seconds = SECONDS_PER_MINUTE - (-this->seconds) % SECONDS_PER_MINUTE;
            }
            if (this->minutes >= 0) {
                this->hours += this->minutes / MINUTES_PER_HOUR;
                this->minutes = this->minutes % MINUTES_PER_HOUR;
            }
            else if (this->hours > 0) {
                this->hours -= (-this->minutes) / MINUTES_PER_HOUR + 1;
                this->minutes = MINUTES_PER_HOUR - (-this->minutes) % MINUTES_PER_HOUR;
            }

            if (this->hours < 0 && this->minutes > 0) {
                ++this->hours;
                this->minutes -= MINUTES_PER_HOUR;
            }
            if (this->minutes < 0 && this->seconds > 0) {
                ++this->minutes;
                this->seconds -= SECONDS_PER_MINUTE;
            }
        }

        friend std::istream& operator>>(std::istream &inputStream, Time &time);
        friend class Time;
    };

    std::string getCountPositiveDigits(int count, int value);
    int readUnit(std::string input, int &index, char seperator);

    Time::Time() : p(new Private()) {
    }

    Time::Time(const Time &time) : p(new Private(*time.p)){
    }

    Time::Time(int hours, int minutes, int seconds) : p(new Private(hours, minutes, seconds)) {
    }

    Time::~Time() {
        delete p;
    }

    int Time::getHours() const {
        return this->p->hours;
    }

    int Time::getMinutes() const {
        return this->p->minutes;
    }

    int Time::getSeconds() const {
        return this->p->seconds;
    }
    
    std::string Time::getTime() const {
        std::ostringstream ouptutStringStream;
        if (this->p->hours < 0 || this->p->minutes < 0 || this->p->seconds < 0)
            ouptutStringStream << '-';
        int digitsCount = std::to_string(std::max(p->MINUTES_PER_HOUR, p->SECONDS_PER_MINUTE)).length();
        ouptutStringStream << getCountPositiveDigits(digitsCount, this->p->hours) << ':'
            << getCountPositiveDigits(digitsCount, this->p->minutes) << ':'
            << getCountPositiveDigits(digitsCount, this->p->seconds);

        return ouptutStringStream.str();
    }

    int Time::getID() const {
        return this->p->ID;
    }

    void Time::add(const Time &time) {
        this->p->hours += time.p->hours;
        this->p->minutes += time.p->minutes;
        this->p->seconds += time.p->seconds;
        this->p->fixFormat();
    }

    void Time::subtract(const Time &time) {
        this->p->hours -= time.p->hours;
        this->p->minutes -= time.p->minutes;
        this->p->seconds -= time.p->seconds;
        this->p->fixFormat();
    }

    std::string Time::toString() const {
        std::stringstream sstream;
        sstream << "H: " << this->p->hours << ", M: " << this->p->minutes << ", S: " << this->p->seconds
            << ", ID: " << this->p->ID;
        return sstream.str();
    }

    std::ostream& operator<<(std::ostream &outputStream, const Time &time) {
        outputStream << time.getTime();
        return outputStream;
    }

    std::istream& operator>>(std::istream &inputStream, Time &time) {
        char sep1, sep2;
        Time tmp;
        std::string input, currentValue;
        bool isNegative = 0;

        getline(inputStream, input);
        if (input[0] == '-')
            isNegative = 1;

        int i = isNegative;
        tmp.p->hours = readUnit(input, i, Time::Private::SEPERATOR);
        ++i;
        tmp.p->minutes = readUnit(input, i, Time::Private::SEPERATOR);
        ++i;
        tmp.p->seconds = readUnit(input, i, Time::Private::SEPERATOR);

        if (isNegative) {
            tmp.p->hours = -tmp.p->hours;
            tmp.p->minutes = -tmp.p->minutes;
            tmp.p->seconds = -tmp.p->seconds;
        }
        tmp.p->fixFormat();
        time = tmp;
        return inputStream;
    }

    Time& Time::operator=(Time time) {
        std::memcpy(this->p, time.p, sizeof(Private));
        return *this;
    }

    bool Time::operator==(const Time &time) const {
        if (this->p->hours == time.p->hours
                && this->p->minutes == time.p->minutes
                && this->p->seconds == time.p->seconds)
            return 1;
        return 0;
    }

    bool Time::operator!=(const Time &time) const {
        return !(*this == time);
    }

    bool Time::operator<(const Time &time) const {
        if (this->p->hours < time.p->hours)
            return 1;
        if (this->p->hours == time.p->hours) {
            if (this->p->minutes < time.p->minutes)
                return 1;
            if (this->p->minutes == time.p->minutes
                    && this->p->seconds < time.p->seconds)
                return 1;
        }
        return 0;
    }
    
    bool Time::operator<=(const Time &time) const {
        return (*this < time || *this == time);
    }

    bool Time::operator>(const Time &time) const {
        return !(*this < time);
    }

    bool Time::operator>=(const Time &time) const {
        return !(*this < time);
    }

    Time Time::operator++() {
        ++this->p->minutes;
        this->p->fixFormat();
        return *this;
    }

    Time Time::operator++(int) {
        Time copy = *this;
        ++this->p->minutes;
        this->p->fixFormat();
        return copy;
    }

    Time Time::operator--() {
        --this->p->minutes;
        this->p->fixFormat();
        return *this;
    }

    Time Time::operator--(int) {
        Time copy = *this;
        --this->p->minutes;
        this->p->fixFormat();
        return copy;
    }

    unsigned int Time::Private::instanceCount = 0;
    const unsigned int Time::Private::MINUTES_PER_HOUR = 60;
    const unsigned int Time::Private::SECONDS_PER_MINUTE = 60;
    const char Time::Private::SEPERATOR = ':';

    std::string getCountPositiveDigits(int count, int value) {
        std::stringstream sstream;
        int positiveValue = abs(value);
        int nrOfDigits = std::to_string(positiveValue).length();
        while (nrOfDigits < count) {
            sstream << 0;
            --count;
        }
        sstream << positiveValue;
        return sstream.str();
    }

    int readUnit(std::string input, int &index, char seperator) {
        std::string currentValue;
        while (isdigit(input[index])) {
            currentValue += input[index];
            ++index;
        }
        if (input[index] == seperator || index == input.size()) {
            return std::stoi(currentValue);
        }
        throw std::ios_base::failure(Error::Time::wrongInputFormat);
    }

}


