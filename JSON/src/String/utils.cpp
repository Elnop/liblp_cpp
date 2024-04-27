#include <cstddef>
#include <string>

bool hasOnlyWhitespacesAround(const std::string& str) {
    size_t i = 0;
    while (i < str.length() && std::isspace(str[i]))
        ++i;
    if (str[i] != '"')
        return false;
    i = str.find('"', i+1)+1;
    while (i < str.length() && std::isspace(str[i]))
        ++i;
    return i == str.length();
}