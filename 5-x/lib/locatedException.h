#include <iostream>
#include <vector>

class LocatedException {
    private:
        std::string exception;

    public:
        static const std::string UNINITIALIZED_OBJECT;
        static const std::string INVALID_INITIALIZATION;

        LocatedException(std::string file, int line, std::string msg);
        std::string what() const;
};
