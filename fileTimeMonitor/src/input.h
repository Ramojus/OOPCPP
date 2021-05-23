#ifndef INPUT_H
#define INPUT_H

#include <iostream>

#include "action.h"

class Input {
    private:
        long unsigned seconds;

    public:
        long unsigned getValue();
        Action getInput();
};

#endif // INPUT_H
