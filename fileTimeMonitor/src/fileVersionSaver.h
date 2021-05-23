#ifndef FILE_VERSION_SAVER_H
#define FILE_VERSION_SAVER_H

#include <iostream>
#include <ctime>

#include "fileVersion.h"

class FileVersionSaver {
    public:
        static void save(FileVersion fileVersion);
};

#endif // FILE_VERSION_SAVER_H
