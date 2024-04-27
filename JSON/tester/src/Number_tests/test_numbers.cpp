#include "JSON_tester.hpp"

bool numbers() {
    TesterContainer<JSON::Number> eight(JSONS_FOLDER"number_eight.json");
    return eight.log_test(&TesterContainer<JSON::Number>::equal, 8);
}