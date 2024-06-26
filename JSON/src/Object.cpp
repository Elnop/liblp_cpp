#include "JSON.hpp"

using JSON::Object;

Object::Object() {}

Object::Object(char const *filename)
{
    std::ifstream ifs(filename);
    if (!ifs.is_open())
        throw std::invalid_argument(std::string(" Constructor : can't open \"") + filename + std::string("\"\n"));
    *this = Object(ifs);
    ifs.close();
}

Object::Object(std::ifstream &ifs)
{
    if (!ifs.is_open())
        throw std::invalid_argument("Object Constructor : stream not open\n");
    ifs >> std::ws;
    if (ifs.get() != '{')
        throw std::invalid_argument("Object Constructor : object must start with {\n");
    ifs >> std::ws;
    char ch = ifs.get();
    while (ch && ch != '}')
    {
        ifs.unget();
        ifs >> std::ws;
        if (ifs.get() != ',')
            ifs.unget();
        ifs >> std::ws;
        std::string key;
        if (ifs.get() != '"') {
            for (std::map<std::string, IType *>::const_iterator it = this->value.begin(); it != this->value.end(); ++it)
                delete it->second;
            throw std::invalid_argument("Object ifstream Constructor : key must start with \"\n");
        }
        for (ch = ifs.get(); ch && ch != '"'; ch = ifs.get())
            key.push_back(ch);
        if (ch != '"')
            throw std::invalid_argument("Object ifstream Constructor : key must end with \"\n");
        if (this->value.find(key) != this->value.end())
        {
            for (std::map<std::string, IType *>::const_iterator it = this->value.begin(); it != this->value.end(); ++it)
                delete it->second;
            throw std::invalid_argument(std::string("Object ifstream Constructor : duplicate key \"") + key + std::string("\"\n"));
        }
        ifs >> std::ws;
        if (ifs.get() != ':') {
            for (std::map<std::string, IType *>::const_iterator it = this->value.begin(); it != this->value.end(); ++it)
                delete it->second;
            throw std::invalid_argument("Object ifstream Constructor : key must be followed by :\n");
        }
        ifs >> std::ws;
        try {
            this->value[key] = parse(ifs);
        } catch (std::exception &e) {
            for (std::map<std::string, IType *>::const_iterator it = this->value.begin(); it != this->value.end(); ++it)
                delete it->second;
            throw std::invalid_argument(std::string("Object ifstream Constructor <- ") + e.what());
        }
        ifs >> std::ws;
        ch = ifs.get();
    }
    if (ch != '}') {
        for (std::map<std::string, IType *>::const_iterator it = this->value.begin(); it != this->value.end(); ++it)
            delete it->second;
        throw std::invalid_argument("Object Constructor : object must end with }\n");
    }
}

Object::Object(std::map<std::string, IType *> value)
{
    this->value = value;
}

Object::Object(const Object &other)
{
    for (std::map<std::string, IType *>::const_iterator it = other.value.begin(); it != other.value.end(); ++it)
        this->value[it->first] = it->second->clone();
}

Object &Object::operator=(const Object &other) {
    if (this != &other) {
        for (std::map<std::string, IType *>::const_iterator it = this->value.begin(); it != this->value.end(); ++it)
            delete it->second;
        this->value.clear();
        for (std::map<std::string, IType *>::const_iterator it = other.value.begin(); it != other.value.end(); ++it)
            this->value[it->first] = it->second->clone();
    }
    return *this;
}

Object *Object::clone() const
{
    Object *new_object = new Object();
    for (std::map<std::string, IType *>::const_iterator it = this->value.begin(); it != this->value.end(); ++it)
        new_object->value[it->first] = it->second->clone();
    return new_object;
}

std::string Object::toString(size_t indentation) const
{
    std::string str;
    for (size_t j = 0; j < indentation; ++j)
        str += "  ";
    str = "{\n";
    for (std::map<std::string, IType *>::const_iterator it = this->value.begin(); it != this->value.end(); ++it)
    {
        for (size_t j = 0; j < indentation+1; ++j)
            str += "  ";
        str += "\"" + it->first + "\": " + it->second->toString(indentation+1);
        if (it != --this->value.end())
            str += ", ";
        str += "\n";
    }
    for (size_t j = 0; j < indentation; ++j)
        str += "  ";
    str += "}";
    return str;
}

Object::~Object()
{
    for (std::map<std::string, IType *>::const_iterator it = this->value.begin(); it != this->value.end(); ++it)
    {
        delete it->second;
    }
    value.clear();
}