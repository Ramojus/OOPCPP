#ifndef __FILE_VERSION_RETRIEVER_H
#define __FILE_VERSION_RETRIEVER_H

#include <iostream>
#include <ctime>

class FileVersionRetriever {
    public:
        static void retrieve(std::string directory, time_t timestamp);
};

#endif // __FILE_VERSION_RETRIEVER_H
