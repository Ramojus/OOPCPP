#include <iostream>
#include <exception>
#include <cassert>

#include "myTime.h"

using namespace std;
using namespace My;

int main () {
    try {
        cout << "\nCreating first object" << endl;
        Time time(-1, 20, 20);
        cout << "To string output: "
             << time.toString() << endl;
        cout << "Get time output: "
             << time.getTime() << endl;

        cout << "\nChecking addition/subtraction operatorations" << endl;
        time.subtract(Time(0, 60, 0));
        assert(time.getHours() == -1 && time.getMinutes() == -39 && time.getSeconds() == -40);

        time.add(Time(3, 40, 40));
        assert(time.getHours() == 2 && time.getMinutes() == 1 && time.getSeconds() == 0);
        cout << "Addition/subtraction operatorations working." << endl;

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
        cout << "All relation operators working." << endl;

        cout << "\nChecking post/pre increment and decrement operators" << endl;
        Time preIncTest(0, 0, 0);
        assert(++preIncTest == Time(0, 1, 0));

        Time postIncTest(0, 0, 0);
        assert(postIncTest++ == Time(0, 0, 0));
        assert(preIncTest.getMinutes() == 1);

        Time preDecTest(0, 0, 0);
        assert(--preDecTest == Time(0, -1, 0));

        Time postDecTest(0, 0, 0);
        assert(postDecTest-- == Time(0, 0, 0));
        assert(postDecTest.getMinutes() == -1);
        cout << "Post/pre increment and decrement operators working." << endl;

        cout << "\nEverything seems to be working correctly" << endl;
    }
    catch (exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }
    catch (...) {
        cout << "Unhandled error occurred" << endl;
    }
}

