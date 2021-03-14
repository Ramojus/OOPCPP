#include <iostream>
#include <sstream>
#include "myTime.h"

namespace Error {
    namespace Time {
        const std::string wrongInputFormat = "Wrong input format. Should be 'H:M:S'";
    }
}

namespace My {
    std::string getCountPositiveDigits(int count, int value);
    int readUnit(std::string input, int &index, char seperator);

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
        this->fixFormat();
    }

    Time::~Time() {
    }

    int Time::getHours() const {
        return this->hours;
    }

    int Time::getMinutes() const {
        return this->minutes;
    }

    int Time::getSeconds() const {
        return this->seconds;
    }
    
    std::string Time::getTime() const {
        std::ostringstream ouptutStringStream;
        if (this->hours < 0 || this->minutes < 0 || this->seconds < 0)
            ouptutStringStream << '-';
        int digitsCount = std::to_string(std::max(MINUTES_PER_HOUR, SECONDS_PER_MINUTE)).length();
        ouptutStringStream << getCountPositiveDigits(digitsCount, this->hours) << ':'
            << getCountPositiveDigits(digitsCount, this->minutes) << ':'
            << getCountPositiveDigits(digitsCount, this->seconds);

        return ouptutStringStream.str();
    }

    int Time::getID() const {
        return this->ID;
    }

    void Time::add(const Time &time) {
        this->hours += time.hours;
        this->minutes += time.minutes;
        this->seconds += time.seconds;
        this->fixFormat();
    }

    void Time::subtract(const Time &time) {
        this->hours -= time.hours;
        this->minutes -= time.minutes;
        this->seconds -= time.seconds;
        this->fixFormat();
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
            this->minutes -= MINUTES_PER_HOUR;
        }
        if (this->minutes < 0 && this->seconds > 0) {
            ++this->minutes;
            this->seconds -= SECONDS_PER_MINUTE;
        }
    }

    std::string Time::toString() const {
        std::stringstream sstream;
        sstream << "H: " << this->hours << ", M: " << this->minutes << ", S: " << this->seconds
            << ", ID: " << this->ID;
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
        tmp.hours = readUnit(input, i, Time::seperator);
        ++i;
        tmp.minutes = readUnit(input, i, Time::seperator);
        ++i;
        tmp.seconds = readUnit(input, i, Time::seperator);

        if (isNegative) {
            tmp.hours = -tmp.hours;
            tmp.minutes = -tmp.minutes;
            tmp.seconds = -tmp.seconds;
        }
        tmp.fixFormat();
        time = tmp;
        return inputStream;
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

    Time Time::operator++() {
        ++this->minutes;
        this->fixFormat();
        return *this;
    }

    Time Time::operator++(int) {
        Time copy = *this;
        ++this->minutes;
        this->fixFormat();
        return copy;
    }

    Time Time::operator--() {
        --this->minutes;
        this->fixFormat();
        return *this;
    }

    Time Time::operator--(int) {
        Time copy = *this;
        --this->minutes;
        this->fixFormat();
        return copy;
    }

    unsigned int Time::instanceCount = 0;
    const unsigned int Time::MINUTES_PER_HOUR = 60;
    const unsigned int Time::SECONDS_PER_MINUTE = 60;
    const char Time::seperator = ':';

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


