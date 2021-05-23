#include <iostream>

#include "currentTimestamp.h"

time_t CurrentTimestamp::timestamp = 0;

void CurrentTimestamp::setTimestamp(time_t timestamp) {
    CurrentTimestamp::timestamp = timestamp;
}

time_t CurrentTimestamp::getTimestamp() {
    return timestamp;
}
