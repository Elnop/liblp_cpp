#include "../JSON.hpp"

template <typename T>
T get(std::string const &key) {
    throw std::invalid_argument(
        std::string(std::string("get<")
        + std::string(unmangle(typeid(T).name()))
        + std::string(">(") + key + std::string(") : invalid generic\n"))
        + std::string(unmangle(typeid(T).name())));
};
template <>
JSON::Object *JSON::Object::get<JSON::Object*>(std::string const &key) {
    if (this->value.find(key) == this->value.end())
        return NULL;
    return dynamic_cast<JSON::Object *>(this->value[key]);
};
template <>
JSON::Array *JSON::Object::get<JSON::Array*>(std::string const &key) {
    if (this->value.find(key) == this->value.end())
        return NULL;
    return dynamic_cast<JSON::Array *>(this->value[key]);
};
template <>
double JSON::Object::get<double>(std::string const &key) {
    if (this->value.find(key) == this->value.end())
        return 0;
    JSON::Number *n = dynamic_cast<JSON::Number *>(this->value[key]);
    return n ? n->value : 0;
};
template <>
bool JSON::Object::get<bool>(std::string const &key) {
    if (this->value.find(key) == this->value.end())
        return false;
    JSON::Boolean *b = dynamic_cast<JSON::Boolean *>(this->value[key]);
    return b ? b->value : false;
};
template <>
std::string JSON::Object::get<std::string>(std::string const &key) {
    if (this->value.find(key) == this->value.end())
        return "";
    JSON::String *s = dynamic_cast<JSON::String *>(this->value[key]);
    return s ? s->value : "";
};