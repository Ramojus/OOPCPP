#include <iostream>
#include <exception>
#include <cassert>
#include <sstream>

#include "myTime.h"
#include "customException.h"

using namespace std;
using namespace My;

int main () {
    try {
        cout << "\nCreating first object" << endl;
        Time time(-1, 20, 20);
        cout << "To string output: " << time.toString() << endl;
        cout << "Get time output: " << time.getTime() << endl;

        cout << "\nChecking addition/subtraction operatorations" << endl;
        time = Time(0, 0, 0);
        time.subtract(Time(0, 64, 0));
        assert(time.getHours() == -1 && time.getMinutes() == -4 && time.getSeconds() == 0);

        time = Time(-1, -20, -20);
        time.add(Time(3, 40, 40));
        assert(time.getHours() == 2 && time.getMinutes() == 20 && time.getSeconds() == 20);
        cout << "Addition/subtraction operatorations working" << endl;

        cout << "\nChecking relation operators" << endl;
        assert (Time(40, 30, 10) == Time(40, 30, 10));

        assert(Time(40, 30, 10) != Time(40, 30, 11));
        assert(Time(40, 30, 10) != Time(40, 31, 10));
        assert(Time(40, 30, 10) != Time(41, 30, 10));

        assert(Time(40, 30, 11) > Time(40, 30, 10));
        assert(Time(40, 31, 10) > Time(40, 30, 10));
        assert(Time(41, 30, 10) > Time(40, 30, 10));

        assert(Time(40, 30, 11) >= Time(40, 30, 10));
        assert(Time(40, 31, 10) >= Time(40, 30, 10));
        assert(Time(41, 30, 10) >= Time(40, 30, 10));
        assert(Time(40, 30, 10) >= Time(40, 30, 10));

        assert(Time(40, 30, 10) < Time(40, 30, 11));
        assert(Time(40, 30, 10) < Time(40, 31, 10));
        assert(Time(40, 30, 10) < Time(41, 30, 10));

        assert(Time(40, 30, 10) <= Time(40, 30, 11));
        assert(Time(40, 30, 10) <= Time(40, 31, 10));
        assert(Time(40, 30, 10) <= Time(41, 30, 10));
        assert(Time(40, 30, 10) <= Time(40, 30, 10));
        cout << "All relation operators working" << endl;

        cout << "\nChecking post/pre increment and decrement operators" << endl;
        time = Time(0, 0, 0);
        assert(++time == Time(0, 1, 0));

        time = Time(0, 0, 0);
        assert(time++ == Time(0, 0, 0));
        assert(time.getMinutes() == 1);

        time = Time(0, 0, 0);
        assert(--time == Time(0, -1, 0));

        time = Time(0, 0, 0);
        assert(time-- == Time(0, 0, 0));
        assert(time.getMinutes() == -1);
        cout << "Post/pre increment and decrement operators working" << endl;

        cout << "\nChecking input/output stream operators" << endl;
        stringstream testStream;
        Time streamOutput = Time(0);
        testStream << time;
        testStream >> streamOutput;
        assert(time == streamOutput);
        cout << "Input/output stream operators working" << endl;

        cout << "\nEverything seems to be working correctly" << endl;
    }
    catch (const CustomException &e) {
        cout << e.what() << endl;
    }
    catch (const invalid_argument &e) {
        cout << "invalid argument: " << e.what() << endl;
    }
    catch (const out_of_range &e) {
        cout << "Out of range: " << e.what() << endl;
    }
    catch (exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }
    catch (...) {
        cout << "Unhandled error occurred" << endl;
    }
}

