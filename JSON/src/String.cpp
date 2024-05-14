#include "JSON.hpp"
#include <iostream>
#include <cstddef>

JSON::String::String(std::string &filename)
{
    std::ifstream ifs(filename.c_str());
    if (!ifs.is_open())
    {
        std::cerr << " Constructor : can't open \"" << filename << "\"\n";
        return ;
    }
    this->value = JSON::String(ifs).value;
    ifs.close();
}

JSON::String::String(std::ifstream &ifs)
{
    if (!ifs.is_open())
        throw std::invalid_argument("String Constructor : stream not open\n");
    ifs >> std::ws;
    if (ifs.get() != '"')
        throw std::invalid_argument("String Constructor : string must start with \"\n");
    char ch = ifs.get();
    for (; ch && ch != '"'; ch = ifs.get())
    {
        this->value.push_back(ch);
    }
    if (ch != '"')
        throw std::invalid_argument("String Constructor : string must end with \"\n");
}

JSON::String::String(std::string str)
{
    this->value = str;
}

JSON::String *JSON::String::clone() const
{
    return new JSON::String(this->value);
}

std::string JSON::String::toString(size_t indentation) const
{
    (void)indentation;
    return std::string("\"")+this->value+std::string("\"");
}
