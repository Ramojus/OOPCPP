#include <iostream>
#include <exception>
#include "myTime.h"

using namespace std;
using namespace My;

int main () {
    try {
        Time time(0, 20, 20);
        cout << time.toString() << endl;

        time.subtract(Time(1, 60, 0));
        cout << time.toString() << endl;

        time.add(Time(3, 40, 20));
        cout << time.toString() << endl;

        Time::setMinutesPerHour(400);
        Time::setSecondsPerMinute(400);
        Time time2(2, 400, 183);
        time2.add(time);
        cout << time2.toString() << endl;
        cout << "Hours: " << time2.getHours() << "\nMinutes: " << time2.getMinutes()
            << "\nSeconds: " << time2.getSeconds() << "\nID: " << time2.getID() << endl;
    }
    catch (exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }
    catch (...) {
        cout << "Unhandled error occurred" << endl;
    }
}

