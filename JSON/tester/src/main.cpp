#include "JSON_tester.hpp"
#include <iostream>

int main() {
    JSON::Boolean True(JSONS_FOLDER"boolean/true.json");
    std::cout << True << " " << std::endl;
    JSON::Boolean False(JSONS_FOLDER"boolean/false.json");
    std::cout << False << " "<< std::endl;
    JSON::Array list(JSONS_FOLDER"boolean/list.json");
    std::cout << list << " " << std::endl;
    JSON::Object object(JSONS_FOLDER"boolean/object.json");
    std::cout << object << " " << std::endl;
    return 0;
}