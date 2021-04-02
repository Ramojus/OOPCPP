#ifndef __TIME_H
#define __TIME_H

#include <iostream>
#include <sstream>

namespace My {

    /**
     * Stores time in three units: hours, minutes, seconds.
     * With every operation formats the time to natural, easy to read format.
     */
    class Time {
        private:
            class Private;
            Private *p;

        public:
            Time();
            Time(const Time &time);
            Time(int minutes);
            Time(int hours, int minutes, int seconds);
            ~Time();
            void init(int minutes);
            void init(int hours, int minutes, int seconds);

        private:
            void validate(std::string file, int line) const;

        public:
            int getHours() const;
            int getMinutes() const;
            int getSeconds() const;
            std::string getTime() const;
            int getID() const;

            /**
             * Adds every unit value of parameter object to current object respective unit values.
             * @param `Time` object to add. Cannot be NULL.
             */
            void add(const Time &time);

            /**
             * Subtracts every unit value of parameter object from current object respective unit values.
             * @param `Time` object to subtract. Cannot be NULL.
             */
            void subtract(const Time &time);

            /**
             * Converts object to string. Meant for debugging. For more readable format use << operator.
             * @return string in "H: `hours`, M: `minutes`, S: `seconds`, ID: `ID`" format.
             */
            std::string toString() const;

            /**
             * Outputs `Time` object to `ostream` in "(-)`hours`:`minutes`:`seconds`" format.
             * @param `Time` object to output.
             * @return `ostream`.
             */
            friend std::ostream& operator<<(std::ostream &outputStream, const Time &time);

            /**
             * Reads input in "(-)`hours`:`minutes`:`seconds`" format with strong exception safety guarantee.
             * @param `Time` object to read from `istream`.
             * @return `istream`.
             */
            friend std::istream& operator>>(std::istream &inputStream, Time &time);

            /**
             * Compares every unit values of parameter object with current object respective unit values.
             * @param `Time` object to compare.
             * @return `bool` value indicating whether parameter object was equal to current object.
             */
            bool operator==(const Time &time) const;

            /**
             * Compares every unit values of parameter object with current object respective unit values.
             * @param `Time` object to compare.
             * @return `bool` value indicating whether parameter obect was not equal to current object.
             */
            bool operator!=(const Time &time) const;

            /**
             * Compares every unit values of parameter object with current object respective unit values.
             * @param `Time` object to compare.
             * @return `bool` value indicating whether parameter object was less than current object.
             */
            bool operator<(const Time &time) const;

            /**
             * Compares every unit values of parameter object with current object respective unit values.
             * @param `Time` object to compare.
             * @return `bool` value indicating whether parameter object was less or equal to current object.
             */
            bool operator<=(const Time &time) const;

            /**
             * Compares every unit values of parameter object with current object respective unit values.
             * @param `Time` object to compare.
             * @return `bool` value indicating whether parameter object was more than current object.
             */
            bool operator>(const Time &time) const;

            /**
             * Compares every unit values of parameter object with current object respective unit values.
             * @param `Time` object to compare.
             * @return `bool` value indicating whether parameter object was more or equal to current object.
             */
            bool operator>=(const Time &time) const;

            Time& operator=(Time time);

            /**
             * Increases `minutes` unit value by one.
             * @return `Time` object after operation.
             */
            Time operator++();

            /**
             * Increases `minutes` unit value by one.
             * @return `Time` object before operation.
             */
            Time operator++(int);

            /**
             * Decreases `minutes` unit value by one.
             * @return `Time` object after operation.
             */
            Time operator--();

            /**
             * Decreases `minutes` unit value by one.
             * @return `Time` object before operation.
             */
            Time operator--(int);
            
            friend Private;
    };
};

#endif // __TIME_H
