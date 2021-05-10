#include <iostream>
#include <exception>

#include "fileMonitor.h"
#include "currentDirectory.h"
#include "input.h"
#include "action.h"

using namespace std;

string getFileName(int argc, char **fileName) {
    return "";
}

string getDirectory(string fileName) {
    return "";
}

void startMonitoring(string directory) {
}

void inputLoop() {
    Input input;
    bool isMonitoring = 1;

    while (isMonitoring) {
        Action action = input.getInput();
        switch(action) {
            case ADD:
                break;
            case REMOVE:
                break;
            case EXIT:
                isMonitoring = 0;
        }
    }
}

int main(int argc, char **fileName) {
    try {
        string fileNameStr = getFileName(argc, fileName);
        string directory = getDirectory(fileNameStr);
        startMonitoring(directory);
        inputLoop();
    }
    catch(exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    catch(...) {
        cout << "Unknown error" << endl;
    }
}
