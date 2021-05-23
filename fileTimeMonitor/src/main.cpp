#include <iostream>
#include <exception>
#include <vector>
#include <cstring>

#include "fileTimeMonitor.h"

using namespace std;

void printUsage() {
}

void setArguments(int argc, char **argv, string &fileName,
                  bool &shouldDeleteSavedVersions) {
    if (argc > 1)
        fileName = argv[1];
    else
        printUsage();

    if (argc > 2) {
        if (strcmp(argv[2], "-d") == 0 && argc == 3)
            shouldDeleteSavedVersions = 1;
        else
            printUsage();
    }
    else
        shouldDeleteSavedVersions = 0;
}

string getFullPath(string fileName) {
    return "";
}

int main(int argc, char **argv) {
    try {
        string fileName;
        bool shouldDeleteSavedVersions;
        setArguments(argc, argv, fileName, shouldDeleteSavedVersions);
        string fullDirectory = getFullPath(fileName);
        File file(fileName, fullDirectory);
        FileTimeMonitor fileTimeMonitor;
        fileTimeMonitor.monitor(file, shouldDeleteSavedVersions);
    }
    catch(exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    catch(...) {
        cout << "Unknown error" << endl;
    }
}
