#ifndef FILE_VERSION_RETRIEVER_H
#define FILE_VERSION_RETRIEVER_H

#include <iostream>
#include <ctime>

#include "fileVersion.h"

class FileVersionRetriever {
    public:
        static void retrieve(FileVersion version);
};

#endif // FILE_VERSION_RETRIEVER_H
