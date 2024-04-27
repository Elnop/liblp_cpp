#include "JSON.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <cmath>
#include <cstdlib>

JSON::Number::Number() {
    this->value = nan("");
    std::cout << this->value << std::endl;
}

JSON::Number::Number(std::string &filename)
{
    std::ifstream ifs(filename.c_str());
    if (!ifs.is_open())
    {
        throw std::invalid_argument(std::string("JSON : Number Constructor : can't open ") + filename);
        return ;
    }
    this->value = JSON::Number(ifs).value;
    ifs.close();
}

JSON::Number::Number(std::ifstream &ifs) {
    std::string line;
    getline(ifs, line);
    this->value = strtod(line.c_str(), NULL);
}