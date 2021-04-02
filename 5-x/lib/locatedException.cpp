#include <iostream>
#include <sstream>
#include "locatedException.h"

using namespace std;

#define IN_FILE "file: "
#define IN_LINE "line: "

const string LocatedException::UNINITIALIZED_OBJECT = "Use of uninitialized object";
const string LocatedException::INVALID_INITIALIZATION = "Attempt to initialize initialized object";

LocatedException::LocatedException(string file, int line, string msg) {
    ostringstream os;
    os << msg << ". " << IN_FILE << file << ", " << IN_LINE << line;
    exception = os.str();
}

string LocatedException::what() const {
    return exception;
}
