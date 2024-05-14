#include "JSON_tester.hpp"
#include <iostream>

int main() {
    try {
        // Parse JSON object from file
        JSON::Object test(JSONS_FOLDER"omfg.json");
        // Access JSON data
        std::cout << test.get<JSON::Array *>("list")
            ->get<JSON::Object *>(1)
            ->get<double>("age")
        << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}