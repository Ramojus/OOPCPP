#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int appendStr(vector<string> &strings, string str) {
    if (str.length()) {
        strings.push_back(str);
        return 0;
    }
    return -1;
}

void getNames(vector<string> &names, string line) {
    string name;
    bool isName = 0;
    for (int i = 0; i < line.length(); ++i) {
        if (isupper(line[i]) && line[i + 1] && islower(line[i + 1])) {
            if (appendStr(names, name) == 0)
                name.clear();
            isName = 1;
            name += line[i];
        }
        else if (islower(line[i]) && isName)
            name += line[i];
        else
            isName = 0;
    }
    appendStr(names, name);
}

int printStrings(vector<string> strings, string msg) {
    cout << msg << '\n';
    if (strings.size() == 0)
        return -1;
    cout << strings[0];
    for (int i = 1; i < strings.size(); ++i)
        cout << ", " << strings[i];
    cout << '\n';
    return 0;
}

int main() {
    cout << "This program scannes list of words and finds every name.\n";
    cout << "Enter list of words. To terminate, press enter on empty line.\n";
    vector<string> names;
    string line;
    bool emptyLine = 0;
    while (!emptyLine) {
        getline(cin, line);
        getNames(names, line);
        if (line.empty())
            emptyLine = 1;
    }
    sort(names.begin(), names.end());
    if (printStrings(names, "Names in alphabetical order:") != 0)
        cout << "No names found\n";
}

