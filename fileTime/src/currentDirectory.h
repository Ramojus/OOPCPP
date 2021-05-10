#include <iostream>

class FilePath {
    private:
        std::string path;
    public:
        std::string getPath();
        void findPath(std::string filename);
};
