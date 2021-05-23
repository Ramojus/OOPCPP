#include <iostream>

#include "fileMonitor.h"

using namespace std;

FileMonitor::FileMonitor(File file) : file(file) {
}

FileMonitor::~FileMonitor() {
    stop();
}

void FileMonitor::start() {
}

void FileMonitor::stop() {
}

