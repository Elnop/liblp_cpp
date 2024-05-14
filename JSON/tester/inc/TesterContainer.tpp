#include "JSON_tester.hpp"
#include <typeinfo>

template<class JSON_Type_Class>
bool equal(JSON_Type_Class instance, typename JSON_Type_Class::value_type value) {
    return instance.value == value;
}

template<class JSON_Type_Class>
JSON_Type_Class log_constructor(char const *filename) {
    std::cout << "+ Constructor : "
    << unmangle(typeid(JSON_Type_Class).name()) << " ( "
    << filename << " ) \n";
    try {
        return JSON_Type_Class(filename);
    } catch (std::exception & e) {
        std::cout << "  Exception : " << e.what() << std::endl;
    } catch (...) {
        std::cout << "unknown exception\n";
    }
    return JSON_Type_Class();
}

template<class JSON_Type_Class>
bool log_test(std::string name, bool isOk) {
    std::cout << name;
    if (isOk)
        std::cout << " OK" << std::endl;
    else
        std::cout << " KO" << std::endl;
    return true;
}
