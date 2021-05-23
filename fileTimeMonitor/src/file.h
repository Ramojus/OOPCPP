#ifndef FILE_H
#define FILE_H

#include <iostream>

class File {
    private:
        std::string directory;
        std::string name;

    public:
        File(std::string name, std::string directory);
        std::string getName();
        std::string getDirectory();
};

#endif // FILE_H
