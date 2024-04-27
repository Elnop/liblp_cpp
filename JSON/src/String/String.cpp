#include "JSON.hpp"
#include "__string_utils.h"
#include <iostream>
#include <cstddef>

JSON::String::String(std::string &filename)
{
    std::ifstream ifs(filename.c_str());
    if (!ifs.is_open())
    {
        std::cerr << "JSON : Constructor : can't open \"" << filename << "\"\n";
        return ;
    }
    this->value = JSON::String(ifs).value;
    ifs.close();
}

JSON::String::String(std::ifstream &ifs)
{
    if (!ifs.is_open())
    {
        std::cerr << "String Constructor : stream not open\n";
        return ;
    }
    std::string line;
    getline(ifs, line);
    size_t firstQuotePos = line.find('"');
    size_t secondQuotePos = line.find('"', firstQuotePos + 1);
    if (firstQuotePos != std::string::npos && secondQuotePos != std::string::npos && hasOnlyWhitespacesAround(line)) {
        this->value = line.substr(firstQuotePos + 1, secondQuotePos - firstQuotePos - 1);
    } else {
        std::cerr << "String Constructor : invalid string\n";
        return ;
    }
}