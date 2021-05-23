#ifndef FILE_VERSION_H
#define FILE_VERSION_H

#include <ctime>
#include <iostream>

class FileVersion {
    private:
        class Name;
        std::time_t timestamp;
        static std::string directory;
        Name *name;

    public:
        FileVersion(std::time_t timestamp);
        ~FileVersion();
        static void setDirectory(std::string directory);
        std::string getName();
};

#endif // FILE_VERSION_H
