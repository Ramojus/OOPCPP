#include <iostream>
#include <sstream>
#include "customException.h"

using namespace std;

const string CustomException::IN_FILE = "file: ";
const string CustomException::IN_LINE = "line: ";

const string CustomException::UNINITIALIZED_OBJECT = "Use of uninitialized object";
const string CustomException::INVALID_INITIALIZATION = "Attempt to initialize initialized object";

CustomException::CustomException(string file, int line, string msg) {
    ostringstream os;
    os << msg << ". " << IN_FILE << file << ", " << IN_LINE << line;
    exception = os.str();
}

string CustomException::what() const {
    return exception;
}
