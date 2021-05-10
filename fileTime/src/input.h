#ifndef __INPUT_H
#define __INPUT_H

#include <iostream>

#include "action.h"

class Input {
    private:
        long unsigned seconds;

    public:
        long unsigned getValue();
        Action getInput();
};

#endif // __INPUT_H
