# JSON Parser Clang CPP98

This project provides a C++ library for parsing JSON files. It includes classes for representing JSON objects, arrays, numbers, boolean and strings, along with methods for parsing JSON data from input streams.

## Features

- **Simple Interface**: Easy-to-use classes for representing JSON data.
- **Parsing**: Parse JSON data from input streams.
- **Object-Oriented Design**: Well-structured classes with virtual functions for extensibility.
- **Cloning**: Support for deep copying of JSON objects and arrays.
- **Type-Safe Accessors**: Template-based accessor methods for safely retrieving values from JSON arrays and objects.

⚠️ you had to compile with clang++ ⚠️

## Usage

## Clone library
*bash*
```bash
mkdir project
cd project
git clone git@github.com:Elnop/liblp_cpp.git
make -C liblp_cpp/JSON
```

## Include Headers
Include the `JSON.hpp` header file in your project.

*main.cpp*
```cpp
#include "JSON.hpp"
```

## Parse JSON
Use the type constructor to parse JSON data from input streams or file.

*main.cpp*
```cpp
#include "JSON.hpp"
#include <iostream>

int main() {
    // Parse JSON object from file
    JSON::Object obj("./test.json");
    std::cout << obj << std::endl;
    return 0;
}
```
## Access Data
Access JSON data using get methods provided by the `Object` and `Array` classes.

*main.cpp*
```cpp
#include "JSON.hpp"
#include <iostream>

int main() {
    // test.json below
    JSON::Object obj("./test.json");
    // Access deep JSON data
    std::cout << "Bob is " << obj . get< JSON::Array * >("list")
        ->get< JSON::Object * >(1)
        ->get< double >("age")
    << std::endl;
    return 0;
}
```

*test.json*
```cpp
{
    "A": "im A",
    "B": "im B",
    "C": "im C",
    "list": [
        {
            "name": "Alice",
            "age": 20
        },
        {
            "name": "Bob",
            "age": 21
        },
        {
            "name": "Crystallizer",
            "age": 22
        }
    ]
}
```

## Compile the project
⚠️ you had to compile with clang++ ⚠️

```bash
clang++ -std=c++98 -I liblp_cpp/JSON/inc main.cpp liblp_cpp/JSON/JSON.a
./a.out
```

## Documentation

- [JSON Wiki](https://fr.wikipedia.org/wiki/JavaScript_Object_Notation)
- [JSON Specification](https://www.json.org/json-en.html)
- [CPP ifstream](https://cplusplus.com/reference/fstream/ifstream/)

## License

This project is licensed under the [WTFPL](https://en.wikipedia.org/wiki/WTFPL)