#include "fileTimeManager.h"
#include "input.h"
#include "action.h"

void inputLoop();

void FileTimeManager::monitor(File file, bool shouldDeleteSavedVersions) {
    // TODO: Start monitoring with a separate thread.
    Monitor monitor(file);
    monitor.start();
    inputLoop();
    monitor.stop();
}

void inputLoop() {
    bool monitoring = 1;
    Input input;
    while(monitoring) {
        Action action = input.getInput();
        time_t value = input.getValue();
        switch(action) {
            case ADD:
                break;
            case REMOVE:
                break;
            case GO_TO:
                break;
            case EXIT:
                monitoring = 0;
                break;
        }
    }
}
