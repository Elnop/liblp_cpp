#include "JSON_tester.hpp"

void numbers() {
    TesterContainer<JSON::Number>(JSONS_FOLDER"numbers/number_eight.json")
	.log_test(&TesterContainer<JSON::Number>::equal, 8);

    TesterContainer<JSON::Number>("not_existing")
	.log_test_exception("JSON : Number Constructor : can't open not_existing");
}