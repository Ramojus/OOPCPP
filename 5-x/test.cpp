#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "src/time.h"

using namespace My;

TEST_CASE("Testing post increment") {
    Time time(6);
    CHECK(time++ == Time(6));
}
