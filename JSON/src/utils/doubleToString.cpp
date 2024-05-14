#include <sstream>
#include <string>

std::string doubleToString(double value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}