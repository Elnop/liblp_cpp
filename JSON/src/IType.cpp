#include "JSON.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, JSON::IType &type){
    os << type.toString();
    return os;
}