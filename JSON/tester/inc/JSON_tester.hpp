#ifndef JSON_TESTER_HPP
# define JSON_TESTER_HPP

# include "../../inc/JSON.hpp"

# define JSONS_FOLDER "tester/json/"

// utils
std::string unmangle(const char *str);

// tests
bool numbers();

#include "toolkit.tpp"

#endif