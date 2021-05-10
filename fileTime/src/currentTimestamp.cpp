#include <iostream>

#include "currentTimestamp.h"

time_t CurrentTimestamp::timestamp = 0;

void CurrentTimestamp::setTimestamp() {
}

time_t CurrentTimestamp::getTimestamp() {
    return timestamp;
}
