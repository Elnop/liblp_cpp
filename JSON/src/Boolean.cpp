#include "JSON.hpp"
#include <iostream>
#include <cstddef>

JSON::Boolean::Boolean() : value(false) {}

JSON::Boolean::Boolean(char const *filename)
{
    std::ifstream ifs(filename);
    if (!ifs.is_open())
    {
        throw std::invalid_argument(std::string("Boolean Constructor : can't open \"") + filename + std::string("\"\n"));
        return ;
    }
    this->value = JSON::Boolean(ifs).value;
    ifs.close();
}

JSON::Boolean::Boolean(std::ifstream &ifs)
{
    const char true_str[] = "true";
    const char false_str[] = "false";
    if (!ifs.is_open())
        throw std::invalid_argument("Boolean Constructor : stream not open\n");
    ifs >> std::ws;
    char ch = ifs.get();
    if (ch == 't')
    {
        size_t i=1;
        while (true_str[i]) {
            if (ifs.get() != true_str[i])
                throw std::invalid_argument("Boolean Constructor : invalid syntaxe\n");
            i++;
        }
        if (true_str[i])
            throw std::invalid_argument("Boolean Constructor : invalid syntaxe\n");
        this->value = true;
    }
    else if (ch == 'f')
    {
        size_t i=1;
        while (false_str[i]) {
            if (ifs.get() != false_str[i])
                throw std::invalid_argument("Boolean Constructor : invalid syntaxe\n");
            i++;
        }
        if (false_str[i])
            throw std::invalid_argument("Boolean Constructor : invalid syntaxe\n");
        this->value = false;
    }
    else
        throw std::invalid_argument("Boolean Constructor : invalid syntaxe\n");
}

JSON::Boolean::Boolean(bool value)
{
    this->value = value;
}

JSON::Boolean *JSON::Boolean::clone() const
{
    return new JSON::Boolean(this->value);
}

std::string JSON::Boolean::toString(size_t indentation) const
{
    (void)indentation;
    return this->value ? "true" : "false";
}
