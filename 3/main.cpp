#include <iostream>
#include "myTime.h"

using namespace std;
using namespace My;

int main () {
    Time time(0, 20, 20);
    cout << time.toString() << endl;

    time.subtract(Time(1, 60, 0));
    cout << time.toString() << endl;

    time.add(Time(3, 40, 20));
    cout << time.toString() << endl;

    Time::setMinutesPerHour(400);
    Time time2(2, 400, 183);
    time2.add(time);
    cout << time2.toString() << endl;
}

