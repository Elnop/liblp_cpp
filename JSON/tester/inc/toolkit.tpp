#include "JSON_tester.hpp"
#include <typeinfo>

template<class JSON_Type_Class>
class TesterContainer {
    private:
        JSON_Type_Class *something_ptr;
        std::string  exception_message;
    public:
        TesterContainer(JSON_Type_Class *inst) : something_ptr(inst) {};
        TesterContainer(std::string filename) {
			this->something_ptr = NULL;
            try {
                this->something_ptr = new JSON_Type_Class(filename);
            } catch (std::exception & e) {
                this->exception_message = e.what();
            } catch (...) {
                std::cout << typeid(JSON_Type_Class).name() << "unknown exception";
            }
        };
        ~TesterContainer() { delete something_ptr; };
        bool equal(typename JSON_Type_Class::value_type value) {
            return this->something_ptr && value == this->something_ptr->value;
        };
        bool log_test(bool (TesterContainer::*method)(typename JSON_Type_Class::value_type value), typename JSON_Type_Class::value_type value) {
            std::cout << "---- Test "\
            << unmangle(typeid(JSON_Type_Class).name()) << " " << value;
            if (((*this).*method)(value))
                std::cout << " OK" << std::endl;
            else
                std::cout << " KO" << std::endl;
            return true;
        }
		bool log_test_exception(std::string message) {
			std::cout << "---- Test exception "\
			<< unmangle(typeid(JSON_Type_Class).name());
			if (this->exception_message == message)
				std::cout << " OK" << std::endl;
			else
			{
				std::cout << " KO" << std::endl;
				std::cout << "Message: " << this->exception_message << std::endl;
			}
			return true;
		}
};