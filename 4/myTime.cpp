#include <iostream>
#include <sstream>
#include "myTime.h"

std::string getCountDigits(int count, int value);

namespace My {

    Time::Time() : ID(instanceCount) {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    Time::Time(int hours, int minutes, int seconds) : ID(instanceCount) {
        ++instanceCount;
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
        fixFormat();
    }

    Time::~Time() {
    }

    int Time::getHours() {
        return this->hours;
    }

    int Time::getMinutes() {
        if (this->hours < 0 && this->minutes > 0)
            return -this->minutes;
        return this->minutes;
    }

    int Time::getSeconds() {
        if ((this->hours < 0 || this->minutes < 0) && this->seconds > 0)
            return -this->seconds;
        return this->seconds;
    }
    
    std::string Time::getTime() {
        std::ostringstream ouptutStringStream;
        if (this->hours < 0 || this->minutes < 0 || this->seconds < 0)
            ouptutStringStream << '-';
        int digitsCount = std::to_string(std::max(MINUTES_PER_HOUR, SECONDS_PER_MINUTE)).length();
        ouptutStringStream << getCountDigits(digitsCount, this->hours) << ':'
            << getCountDigits(digitsCount, this->minutes) << ':'
            << getCountDigits(digitsCount, this->seconds);

        return ouptutStringStream.str();
    }

    int Time::getID() {
        return this->ID;
    }

    void Time::add(Time time) {
        this->hours += time.hours;
        this->minutes += time.minutes;
        this->seconds += time.seconds;
        fixFormat();
    }

    void Time::subtract(Time time) {
        this->hours -= time.hours;
        this->minutes -= time.minutes;
        this->seconds -= time.seconds;
        fixFormat();
    }

    void Time::fixFormat() {
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
            this->minutes -= 60;
        }
        if (this->minutes < 0 && this->seconds > 0) {
            ++this->minutes;
            this->seconds -= 60;
        }
    }

    std::string Time::toString() {
        std::stringstream sstream;
        sstream << "H: " << this->hours << ", M: " << this->minutes << ", S: " << this->seconds
            << ", ID: " << this->ID;
        return sstream.str();
    }

    bool Time::operator==(const Time &time) const {
        if (this->hours == time.hours
                && this->minutes == time.minutes
                && this->seconds == time.seconds)
            return 1;
        return 0;
    }

    bool Time::operator!=(const Time &time) const {
        return !(*this == time);
    }

    bool Time::operator>(const Time &time) const {

        if (this->hours > time.hours)
            return 1;
        if (this->hours == time.hours) {
            if (this->minutes > time.minutes)
                return 1;
            if (this->minutes == time.minutes
                    && this->seconds > time.seconds)
                return 1;
        }
        return 0;
    }

    bool Time::operator>=(const Time &time) const {
        if (*this == time || *this > time)
            return 1;
        return 0;
    }

    bool Time::operator<(const Time &time) const {
        return !(*this >= time);
    }
    
    bool Time::operator<=(const Time &time) const {
        return !(*this > time);
    }

    Time &Time::operator++() {
        ++this->minutes;
        fixFormat();
        return *this;
    }

    Time Time::operator++(int) {
        Time copy = *this;
        ++this->minutes;
        fixFormat();
        return copy;
    }

    Time &Time::operator--() {
        --this->minutes;
        fixFormat();
        return *this;
    }

    Time Time::operator--(int) {
        Time copy = *this;
        --this->minutes;
        fixFormat();
        return copy;
    }

    unsigned int Time::instanceCount = 0;
    const unsigned int Time::MINUTES_PER_HOUR = 60;
    const unsigned int Time::SECONDS_PER_MINUTE = 60;
}

std::string getCountDigits(int count, int value) {
    std::stringstream sstream;
    while (std::to_string(value).length() < count) {
        sstream << 0;
        --count;
    }
    sstream << (value < 0? -value: value);
    return sstream.str();
}

