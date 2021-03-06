#include <iostream>
#include <sstream>
#include "myTime.h"

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

    void Time::setMinutesPerHour(unsigned int minutesPerHour) {
        Time::minutesPerHour = minutesPerHour;
    }

    void Time::setSecondsPerMinute(unsigned int secondsPerMinute) {
        Time::secondsPerMinute = secondsPerMinute;
    }

    int Time::getHours() {
        return this->hours;
    }

    int Time::getMinutes() {
        return this->minutes;
    }

    int Time::getSeconds() {
        return seconds;
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
        if (this->seconds > 0) {
            this->minutes += this->seconds / secondsPerMinute;
            this->seconds = this->seconds % secondsPerMinute;
        }
        else {
            this->minutes -= (-this->seconds) / secondsPerMinute + 1;
            this->seconds = secondsPerMinute - (-this->seconds) % secondsPerMinute;
        }
        if (this->minutes > 0) {
            this->hours += this->minutes / minutesPerHour;
            this->minutes = this->minutes % minutesPerHour;
        }
        else {
            this->hours -= (-this->minutes) / minutesPerHour + 1;
            this->minutes = minutesPerHour - (-this->minutes) % minutesPerHour;
        }
    }

    std::string Time::toString() {
        std::stringstream sstream;
        sstream << getMin2digits(this->hours) << ':'
            << getMin2digits(this->minutes) << ':'
            << getMin2digits(this->seconds) << '\n'
            << "ID: " << this->ID << '\n'
            << "minutesPerHour: " << this->minutesPerHour << '\n'
            << "secondsPerMinute: " << this->secondsPerMinute << '\n';
        return sstream.str();
    }

    std::string Time::getMin2digits(int value) {
        std::stringstream sstream;
        if (value < 10) {
            if (value < 0) {
                sstream << '-';
                value = -value;
            }
            sstream << 0;
        }
        sstream << value;
        return sstream.str();
    }

    unsigned int Time::instanceCount = 0;
    unsigned int Time::minutesPerHour = 60;
    unsigned int Time::secondsPerMinute = 60;
}

