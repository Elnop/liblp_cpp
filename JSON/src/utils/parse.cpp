#include "JSON.hpp"

JSON::IType *JSON::parse(std::ifstream &ifs)
{
    if (!ifs.is_open())
        throw std::invalid_argument("Boolean Constructor : stream not open\n");
    ifs >> std::ws;
    char ch = ifs.get();
    ifs.unget();
    if (ch == '"')
        return new JSON::String(ifs);
    if (ch == 't' || ch == 'f')
        return new JSON::Boolean(ifs);
    if (ch == '[')
        return new JSON::Array(ifs);
    if (std::isdigit(ch) || ch == '-')
        return new JSON::Number(ifs);
    if (ch == '{')
        return new JSON::Object(ifs);
    return NULL;
}