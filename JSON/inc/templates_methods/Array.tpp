#include "../JSON.hpp"

template <>
JSON::Object *JSON::Array::get<JSON::Object*>(size_t key) {
        return dynamic_cast<JSON::Object *>(this->value[key]);
}
template <>
JSON::Array *JSON::Array::get<JSON::Array*>(size_t key) {
    return dynamic_cast<JSON::Array *>(this->value[key]);
}
template <>
double JSON::Array::get<double>(size_t key) {
    JSON::Number *n = dynamic_cast<JSON::Number *>(this->value[key]);
    return n ? n->value : 0;
};
template <>
bool JSON::Array::get<bool>(size_t key) {
    JSON::Boolean *b = dynamic_cast<JSON::Boolean *>(this->value[key]);
    return b ? b->value : false;
};
template <>
std::string JSON::Array::get<std::string>(size_t key) {
    JSON::String *s = dynamic_cast<JSON::String *>(this->value[key]);
    return s ? s->value : "";
};