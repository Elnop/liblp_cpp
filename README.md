# JSON Parser

This project provides a C++ library for parsing JSON files. It includes classes for representing JSON objects, arrays, numbers, and strings, along with methods for parsing JSON data from input streams.

## Features

- **Simple Interface**: Easy-to-use classes for representing JSON data.
- **Parsing**: Parse JSON data from input streams.
- **Object-Oriented Design**: Well-structured classes with virtual functions for extensibility.
- **Cloning**: Support for deep copying of JSON objects and arrays.
- **Type-Safe Accessors**: Template-based accessor methods for safely retrieving values from JSON arrays and objects.

## Usage

1. **Include Headers**: Include the `JSON.hpp` header file in your project.
2. **Parse JSON**: Use the `parse` function to parse JSON data from input streams.
3. **Access Data**: Access JSON data using accessor methods provided by the `Object` and `Array` classes.
4. **Clone Objects**: Clone JSON objects and arrays using the `clone` method for deep copying.

## Example

```cpp
#include "JSON.hpp"
#include <iostream>

int main() {
    try {
        // Parse JSON object from file
        JSON::Object test("example.json");
        
        // Access JSON data
        std::cout << "Parsed JSON Object:\n" << test << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
```

## License

This project is licensed under the MIT License - see the [LICENSE](https://opensource.org/license/mit) file for details.

## Links

- [JSON Wiki](https://fr.wikipedia.org/wiki/JavaScript_Object_Notation)
- [JSON Specification](https://www.json.org/json-en.html)