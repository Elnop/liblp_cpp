#include "JSON.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <cmath>
#include <cstdlib>
#include <algorithm>

JSON::Number::Number() {
    this->value = 0;
}

JSON::Number::Number(double value) {
    this->value = value;
}

JSON::Number::Number(char const *filename)
{
    std::ifstream ifs(filename);
    if (!ifs.is_open())
        throw std::invalid_argument(std::string(" Number Constructor (char *filename) : can't open ") + filename);
    this->value = JSON::Number(ifs).value;
    ifs.close();
}

std::string rdstr(std::ifstream& ifs, int length) {
    std::string result;
    result.reserve(length);
    char ch;
    while (length-- && ifs.get(ch))
    {
        result.push_back(ch);
    }
    return result;
}

int count_digits(std::ifstream& ifs) {
    int count = 0;
    char ch;
    std::streampos save_pos = ifs.tellg();
    while (ifs.get(ch) && std::isdigit(ch))
        ++count;
    ifs.clear();
    ifs.seekg(save_pos);
    return count;
}

JSON::Number::Number(std::ifstream &ifs) {
    std::string line = rdstr(ifs, count_digits(ifs));
    this->value = strtod(line.c_str(), NULL);
	if (this->value == 0 && line[0] != '0')
		throw std::invalid_argument(std::string(" Number Constructor (ifstream) : invalid number ") + line);
}

JSON::Number::Number(std::string str) {
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
    char *end;
    this->value = strtod(str.c_str(), &end);
	if (*end && *end != ',' && *end != ']' && *end != '}')
		throw std::invalid_argument(std::string(" Number Constructor (string) : invalid number in \"") + str + std::string("\"") );
}

JSON::Number *JSON::Number::clone() const {
    return new JSON::Number(this->value);
}

std::string JSON::Number::toString(size_t indentation) const {
    (void)indentation;
    return doubleToString(this->value);
}
