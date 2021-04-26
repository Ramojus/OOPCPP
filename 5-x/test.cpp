#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "src/time.h"
#include "locatedException.h"

using namespace My;
using namespace std;

TEST_CASE("Object initialization") {
    REQUIRE_NOTHROW(Time time(0));
}

TEST_CASE("Initialization values and getters") {
    Time time(3, 20, 40);
    CHECK(time.getHours() == 3);
    CHECK(time.getMinutes() == 20);
    CHECK(time.getSeconds() == 40);
}

TEST_CASE("Auto ID") {
    int currentID = Time(0).getID();
    CHECK(Time(0).getID() == ++currentID);
    CHECK(Time(0).getID() == ++currentID);
    CHECK(Time(0).getID() == ++currentID);
}

TEST_CASE("Comparison operators") {
    CHECK(Time(40, 30, 10) == Time(40, 30, 10));

    CHECK(Time(40, 30, 10) != Time(40, 30, 11));
    CHECK(Time(40, 30, 10) != Time(40, 31, 10));
    CHECK(Time(40, 30, 10) != Time(41, 30, 10));
    CHECK_FALSE(Time(40, 30, 10) == Time(40, 30, 11));
    CHECK_FALSE(Time(40, 30, 10) == Time(40, 31, 10));
    CHECK_FALSE(Time(40, 30, 10) == Time(41, 30, 10));

    CHECK(Time(40, 30, 11) > Time(40, 30, 10));
    CHECK(Time(40, 31, 10) > Time(40, 30, 10));
    CHECK(Time(41, 30, 10) > Time(40, 30, 10));
    CHECK_FALSE(Time(40, 30, 11) <= Time(40, 30, 10));
    CHECK_FALSE(Time(40, 31, 10) <= Time(40, 30, 10));
    CHECK_FALSE(Time(41, 30, 10) <= Time(40, 30, 10));

    CHECK(Time(40, 30, 11) >= Time(40, 30, 10));
    CHECK(Time(40, 31, 10) >= Time(40, 30, 10));
    CHECK(Time(41, 30, 10) >= Time(40, 30, 10));
    CHECK(Time(40, 30, 10) >= Time(40, 30, 10));
    CHECK_FALSE(Time(40, 30, 11) < Time(40, 30, 10));
    CHECK_FALSE(Time(40, 31, 10) < Time(40, 30, 10));
    CHECK_FALSE(Time(41, 30, 10) < Time(40, 30, 10));
    CHECK_FALSE(Time(40, 30, 10) < Time(40, 30, 10));

    CHECK(Time(40, 30, 10) < Time(40, 30, 11));
    CHECK(Time(40, 30, 10) < Time(40, 31, 10));
    CHECK(Time(40, 30, 10) < Time(41, 30, 10));
    CHECK_FALSE(Time(40, 30, 10) >= Time(40, 30, 11));
    CHECK_FALSE(Time(40, 30, 10) >= Time(40, 31, 10));
    CHECK_FALSE(Time(40, 30, 10) >= Time(41, 30, 10));

    CHECK(Time(40, 30, 10) <= Time(40, 30, 11));
    CHECK(Time(40, 30, 10) <= Time(40, 31, 10));
    CHECK(Time(40, 30, 10) <= Time(41, 30, 10));
    CHECK(Time(40, 30, 10) <= Time(40, 30, 10));
    CHECK_FALSE(Time(40, 30, 10) > Time(40, 30, 11));
    CHECK_FALSE(Time(40, 30, 10) > Time(40, 31, 10));
    CHECK_FALSE(Time(40, 30, 10) > Time(41, 30, 10));
    CHECK_FALSE(Time(40, 30, 10) > Time(40, 30, 10));
}

TEST_CASE("Input/output stream operators") {
    stringstream testStream;
    Time streamOutput(0);
    Time negativeTime(-3, -4, -30);
    Time positiveTime(30, 40, 3);

    testStream << negativeTime;
    testStream >> streamOutput;
    CHECK(negativeTime == streamOutput);

    testStream.clear();
    testStream << positiveTime;
    testStream >> streamOutput;
    CHECK(positiveTime == streamOutput);
}

TEST_CASE("Post/pre increment and decrement operators") {
    Time time(0, 0, 0);
    CHECK(++time == Time(0, 1, 0));

    time = Time(0, 0, 0);
    CHECK(time++ == Time(0, 0, 0));
    CHECK(time == Time(0, 1, 0));

    time = Time(0, 0, 0);
    CHECK(--time == Time(0, -1, 0));

    time = Time(0, 0, 0);
    CHECK(time-- == Time(0, 0, 0));
    CHECK(time == Time(0, -1, 0));
}

TEST_CASE("Exceptions") {
    Time time;
    CHECK_THROWS(time.getHours());
    CHECK_THROWS_AS(time.getHours(), LocatedException);

    time.init(32);
    stringstream testStream;
    testStream << "8:-9:32";
    CHECK_THROWS(testStream >> time);
    CHECK(time == Time(32));
    
}

TEST_CASE("Deep copying") {
    Time time(2, 30, 0);
    Time copy1(time);
    CHECK(time == copy1);
    ++time;
    CHECK(time != copy1);

    Time copy2 = time;
    CHECK(time == copy2);
    ++time;
    CHECK(time != copy2);
}

TEST_CASE("Memory leaks") {
    CHECK(Time::getLiveInstanceCount() == 0);
    {
        Time time(0);
        time.add(423);
        Time time2(time);
        Time time3 = time;
        Time uninitializedTime;
        CHECK(Time::getLiveInstanceCount() == 3);
        uninitializedTime.init(0);
        CHECK(Time::getLiveInstanceCount() == 4);
    }
    CHECK(Time::getLiveInstanceCount() == 0);
}

TEST_CASE("Formatting") {
    CHECK(Time(-1, 20, 20) == Time(0, -39, -40));
    CHECK(Time(1, -20, 0) == Time(0, 40, 0));
    CHECK(Time(0, 1, -20) == Time(0, 0, 40));

    CHECK(Time(0, 123, 0) == Time(2, 3, 0));
    CHECK(Time(0, 0, 200) == Time(0, 3, 20));
}

TEST_CASE("subtract method") {
    Time time(0, 0, 0);
    time.subtract(Time(0, 64, 2));
    CHECK(time.getHours() == -1);
    CHECK(time.getMinutes() == -4);
    CHECK(time.getSeconds() == -2);
}

TEST_CASE("add method") {
    Time time(0, 0, 0);
    time.add(Time(0, 64, 2));
    CHECK(time.getHours() == 1);
    CHECK(time.getMinutes() == 4);
    CHECK(time.getSeconds() == 2);
}

