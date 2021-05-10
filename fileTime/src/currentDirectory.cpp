#include <iostream>

#include "currentDirectory.h"

using namespace std;

string FilePath::getPath() {
    return path;
}

void FilePath::findPath(string filename) {
    path = "";
}
