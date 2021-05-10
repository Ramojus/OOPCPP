#ifndef __FILE_VERSION_SAVER_H
#define __FILE_VERSION_SAVER_H

#include <iostream>
#include <ctime>

class FileVersionSaver {
    public:
        static void save(std::string directory, time_t timestamp);
};

#endif // __FILE_VERSION_SAVER_H
