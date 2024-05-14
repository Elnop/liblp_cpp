#ifndef JSON_TESTER_HPP
# define JSON_TESTER_HPP

# include "../../inc/JSON.hpp"

# define JSONS_FOLDER "tester/json/"

// utils
std::string unmangle(const char *str);
void logObject(JSON::Object &map);
// tests
void test_number();
void test_array();
void test_object();

#include "TesterContainer.tpp"

#endif