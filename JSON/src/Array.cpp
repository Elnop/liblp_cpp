#include "JSON.hpp"
#include <iostream>
#include <stdexcept>
#include <cctype>

using JSON::Array;

Array::Array() {}

Array::Array(std::vector<IType *> value) {
    this->value = value;
}

Array::Array(char const *filename)
{
    std::ifstream ifs(filename);
    if (!ifs.is_open())
        throw std::invalid_argument(std::string(" Array Constructor : can't open ") + filename);
    *this = Array(ifs);
    ifs.close();
}

Array::Array(std::ifstream &ifs) {
    ifs >> std::ws;
    if (ifs.get() != '[') {
        for (size_t i = 0; i < this->value.size(); ++i)
            delete this->value[i];
        throw std::invalid_argument(" Array ifstream Constructor : array must start with [");
    }
    ifs >> std::ws;
    char ch = ifs.get();
    while (ch && ch != ']')
    {
        ifs.unget();
        ifs >> std::ws;
        if (ifs.get() != ',')
            ifs.unget();
        ifs >> std::ws;
        try {
            this->value.push_back(JSON::parse(ifs));
        } catch (std::exception &e) {
            for (size_t i = 0; i < this->value.size(); ++i)
                delete this->value[i];
            throw std::invalid_argument(std::string("Array ifstream Constructor <- ") + e.what());
        }
        ifs >> std::ws;
        ch = ifs.get();
    }
    if (ch != ']') {
        for (size_t i = 0; i < this->value.size(); ++i)
            delete this->value[i];
        throw std::invalid_argument(" Array ifstream Constructor : array must end with ]");
    }
}

Array::Array(const Array &other) {
    for (size_t i = 0; i < other.value.size() && other.value[i]; ++i)
        this->value.push_back(other.value[i]->clone());
}

Array &Array::operator=(const Array &other) {
    if (this != &other) {
        for (size_t i = 0; i < value.size(); ++i)
            delete this->value[i];
        this->value.clear();
        for (size_t i = 0; i < other.value.size() && other.value[i]; ++i)
            this->value.push_back(other.value[i]->clone());
    }
    return *this;
}

Array *Array::clone() const {
    Array *new_array = new Array();
    for (size_t i = 0; i < this->value.size(); ++i)
        new_array->value.push_back(this->value[i]->clone());
    return new_array;
}

std::string Array::toString(size_t indentation) const {
    std::string str;
    for (size_t j = 0; j < indentation; ++j)
        str += "  ";
    str = "[\n";
    for (size_t i = 0; i < this->value.size(); ++i) {
        for (size_t j = 0; j < indentation+1; ++j)
            str += "  ";
        str += this->value[i]->toString(indentation+1);
        if (i + 1 < this->value.size())
            str += ", ";
        str += "\n";
    }
    for (size_t j = 0; j < indentation; ++j)
        str += "  ";
    str += "]";
    return str;
}

Array::~Array() {
    for (size_t i = 0; i < value.size(); ++i) {
        delete this->value[i];
    }
    value.clear();
}
