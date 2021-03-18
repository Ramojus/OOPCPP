#include <iostream>
#include <sstream>
#include <cstring>
#include "myTime.h"
#include "customException.h"

using namespace std;

namespace Error {
    const string WRONG_INPUT_FORMAT = "Wrong input format. Should be '(-)H:M:S' e.g. -3:40:20";
}

namespace My {
    class Time::Private {
        private:
            int hours;
            int minutes;
            int seconds;
            int ID;
            static const unsigned int MINUTES_PER_HOUR;
            static const unsigned int SECONDS_PER_MINUTE;
            static const char SEPARATOR;
            static unsigned int instanceCount;

        public:
            Private(int hours, int minutes, int seconds);
            ~Private();
            void fixFormat();

        friend istream& operator>>(istream &inputStream, Time &time);
        friend Time;
    };

    unsigned int Time::Private::instanceCount = 0;
    const unsigned int Time::Private::MINUTES_PER_HOUR = 60;
    const unsigned int Time::Private::SECONDS_PER_MINUTE = 60;
    const char Time::Private::SEPARATOR = ':';

    Time::Private::Private(int hours, int minutes, int seconds) : ID(instanceCount) {
        ++this->instanceCount;
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
        this->fixFormat();
    }

    Time::Private::~Private() {
    }

    void Time::Private::fixFormat() {
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

    string getCountPositiveDigits(int count, int value);
    int readUnit(string input, int &index, char seperator);

    Time::Time() : p(NULL) {
    }

    Time::Time(const Time &time) : p(new Private(*time.p)) {
    }

    Time::Time(int minutes) : p(new Private(0, minutes, 0)) {
    }

    Time::Time(int hours, int minutes, int seconds) : p(new Private(hours, minutes, seconds)) {
    }

    Time::~Time() {
        delete p;
    }

    void Time::init(int minutes) {
        if (this->p != NULL)
            throw CustomException(__FILE__, __LINE__, CustomException::INVALID_INITIALIZATION);
        p = new Private(0, minutes, 0);
    }

    void Time::init(int hours, int minutes, int seconds) {
        if (this->p != NULL)
            throw CustomException(__FILE__, __LINE__, CustomException::INVALID_INITIALIZATION);
        p = new Private(hours, minutes, seconds);
    }

    void Time::validate(string file, int line) const {
        if (this->p == NULL)
            throw CustomException(file, line, CustomException::UNINITIALIZED_OBJECT);
    }

    int Time::getHours() const {
        this->validate(__FILE__, __LINE__);
        return this->p->hours;
    }

    int Time::getMinutes() const {
        this->validate(__FILE__, __LINE__);
        return this->p->minutes;
    }

    int Time::getSeconds() const {
        this->validate(__FILE__, __LINE__);
        return this->p->seconds;
    }

    string Time::getTime() const {
        this->validate(__FILE__, __LINE__);
        ostringstream ouptutStringStream;
        if (this->p->hours < 0 || this->p->minutes < 0 || this->p->seconds < 0)
            ouptutStringStream << '-';
        int digitsCount = to_string(max(p->MINUTES_PER_HOUR, p->SECONDS_PER_MINUTE)).length();
        ouptutStringStream << getCountPositiveDigits(digitsCount, this->p->hours) << ':'
            << getCountPositiveDigits(digitsCount, this->p->minutes) << ':'
            << getCountPositiveDigits(digitsCount, this->p->seconds);

        return ouptutStringStream.str();
    }

    int Time::getID() const {
        return this->p->ID;
    }

    void Time::add(const Time &time) {
        this->validate(__FILE__, __LINE__);
        this->p->hours += time.p->hours;
        this->p->minutes += time.p->minutes;
        this->p->seconds += time.p->seconds;
        this->p->fixFormat();
    }

    void Time::subtract(const Time &time) {
        this->validate(__FILE__, __LINE__);
        this->p->hours -= time.p->hours;
        this->p->minutes -= time.p->minutes;
        this->p->seconds -= time.p->seconds;
        this->p->fixFormat();
    }

    string Time::toString() const {
        this->validate(__FILE__, __LINE__);
        stringstream sstream;
        sstream << "H: " << this->p->hours << ", M: " << this->p->minutes << ", S: " << this->p->seconds
            << ", ID: " << this->p->ID;
        return sstream.str();
    }

    ostream& operator<<(ostream &outputStream, const Time &time) {
        time.validate(__FILE__, __LINE__);
        outputStream << time.getTime();
        return outputStream;
    }

    // reads input in (-)H:M:S format with strong exception safety guarantee
    istream& operator>>(istream &inputStream, Time &time) {
        time.validate(__FILE__, __LINE__);
        char sep1, sep2;
        Time tmp = Time(0);
        string input, currentValue;
        bool isNegative = 0;

        getline(inputStream, input);
        if (input[0] == '-')
            isNegative = 1;

        int i = isNegative;
        tmp.p->hours = readUnit(input, i, Time::Private::SEPARATOR);
        ++i;
        tmp.p->minutes = readUnit(input, i, Time::Private::SEPARATOR);
        ++i;
        tmp.p->seconds = readUnit(input, i, Time::Private::SEPARATOR);

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
        time.validate(__FILE__, __LINE__);
        memcpy(this->p, time.p, sizeof(Private));
        return *this;
    }

    bool Time::operator==(const Time &time) const {
        this->validate(__FILE__, __LINE__);
        time.validate(__FILE__, __LINE__);
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
        this->validate(__FILE__, __LINE__);
        time.validate(__FILE__, __LINE__);
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
        this->validate(__FILE__, __LINE__);
        ++this->p->minutes;
        this->p->fixFormat();
        return *this;
    }

    Time Time::operator++(int) {
        this->validate(__FILE__, __LINE__);
        Time copy = *this;
        ++this->p->minutes;
        this->p->fixFormat();
        return copy;
    }

    Time Time::operator--() {
        this->validate(__FILE__, __LINE__);
        --this->p->minutes;
        this->p->fixFormat();
        return *this;
    }

    Time Time::operator--(int) {
        this->validate(__FILE__, __LINE__);
        Time copy = *this;
        --this->p->minutes;
        this->p->fixFormat();
        return copy;
    }

    string getCountPositiveDigits(int count, int value) {
        stringstream sstream;
        int positiveValue = abs(value);
        int nrOfDigits = to_string(positiveValue).length();
        while (nrOfDigits < count) {
            sstream << 0;
            --count;
        }
        sstream << positiveValue;
        return sstream.str();
    }

    int readUnit(string input, int &index, char seperator) {
        string currentValue;
        while (isdigit(input[index])) {
            currentValue += input[index];
            ++index;
        }
        if (input[index] == seperator || index == input.size()) {
            return stoi(currentValue);
        }
        throw ios_base::failure(Error::WRONG_INPUT_FORMAT);
    }

}

