#include <sstream>

#include "fileVersion.h"

using namespace std;

string FileVersion::directory = "";

class FileVersion::Name {
    private:
        string name;
    public:
        Name(time_t timestamp);
        string get();
};

FileVersion::Name::Name(time_t timestamp) {
    ostringstream stream;
    stream << timestamp;
    this->name = stream.str();
}

string FileVersion::Name::get() {
    return name;
}

FileVersion::FileVersion(std::time_t timestamp) {
    this->timestamp = timestamp;
    this->name = new FileVersion::Name(timestamp);
}

FileVersion::~FileVersion() {
    delete this->name;
}

void FileVersion::setDirectory(std::string directory) {
    FileVersion::directory = directory;
}

std::string FileVersion::getName() {
    return this->name->get();
}
