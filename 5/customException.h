#include <iostream>
#include <vector>

class CustomException {
    private:
        std::string exception;

        static const std::string IN_FILE;
        static const std::string IN_LINE;

    public:
        static const std::string UNINITIALIZED_OBJECT;
        static const std::string INVALID_INITIALIZATION;

        CustomException(std::string file, int line, std::string msg);
        std::string what() const;
};
