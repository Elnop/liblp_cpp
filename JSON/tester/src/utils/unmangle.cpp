#include <cxxabi.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream>

std::string unmange(const char *str) {
    int status = -4;
    char *buff = (char *)malloc(sizeof(char) * std::strlen(str));
    size_t length;
    abi::__cxa_demangle	(str , buff , &length , &status);
    std::string out(buff);
    free(buff);
    return out;
}