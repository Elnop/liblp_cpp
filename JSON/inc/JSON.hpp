#ifndef JSON_HPP
# define JSON_HPP
# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <vector>
# include <typeinfo>
# include <ostream>

std::string unmangle(const char *str);
std::string doubleToString(double value);

namespace JSON {
	class IType {
		public:
			virtual ~IType() {};
			virtual IType *clone() const = 0;
			virtual std::string toString(size_t indentation=0) const = 0;
	};
	class Object;
	IType *parse(std::ifstream &ifs);
	class Number : public IType {
		public:
			typedef double value_type;
			double value;
			Number();
			Number(double value);
			Number(std::ifstream &ifs);
			Number(char const *filename);
			Number(std::string str);
			// Number &operator=(const Number &other);
			Number *clone() const;
			std::string toString(size_t indentation=0) const;
			~Number(){};
	};
	class String : public IType {
		public:
			std::string value;
			String();
			String(std::string value);
			String(std::string &filename);
			String(std::ifstream &ifs);
			String *clone() const;
			std::string toString(size_t indentation=0) const;
			~String(){};
	};
	class Boolean : public IType {
		public:
			bool value;
			Boolean();
			Boolean(bool value);
			Boolean(char const *filename);
			Boolean(std::ifstream &ifs);
			Boolean *clone() const;
			std::string toString(size_t indentation=0) const;
			~Boolean(){};
	};
	class Array : public IType {
		public:
			typedef std::vector<IType *> value_type;
			std::vector<IType *> value;
			Array();
			Array(std::vector<IType *> value);
			Array(char const *filename);
			Array(std::ifstream &ifs);
			Array *clone() const;
			template <typename T>
            inline T get(size_t key);
			template <>
			inline Object *get<Object*>(size_t key);
			template <>
			inline Array *get<Array*>(size_t key);
			template <>
			inline double get<double>(size_t key);
			template <>
			inline bool get<bool>(size_t key);
			template <>
			inline std::string get<std::string>(size_t key);
			std::string toString(size_t indentation=0) const;
			Array &operator=(const Array &other) {
				if (this != &other) {
					this->value.clear();
					for (size_t i = 0; i < other.value.size(); ++i)
						this->value.push_back(other.value[i]->clone());
				}
				return *this;
			}
			~Array();
	};
	class Object : public IType {
		public:
			std::map<std::string, IType *> value;
			Object();
			Object(std::map<std::string, IType *> value);
			Object(char const *filename);
			Object(std::ifstream &ifs);
			Object *clone() const;
			template <typename T>
            inline T get(std::string const &key);
			template <>
			inline Object *get<Object*>(std::string const &key);
			template <>
			inline Array *get<Array*>(std::string const &key);
			template <>
			inline double get<double>(std::string const &key);
			template <>
			inline bool get<bool>(std::string const &key);
			template <>
			inline std::string get<std::string>(std::string const &key);
			std::string toString(size_t indentation=0) const;
			Object &operator=(const Object &other) {
				if (this != &other) {
					this->value.clear();
					for (std::map<std::string, IType *>::const_iterator it = other.value.begin(); it != other.value.end(); ++it)
						this->value[it->first] = it->second->clone();
				}
				return *this;
			}
			~Object();
	};
	// class Boolean : public IType {
	// 	public:
	// 		bool value;
	// 		bool parse(std::ifstream &ifs);
	// };
	// class Null : public IType {
	// 	public:
	// 		void *value;
	// 		void *parse(std::ifstream &ifs);
	// };
}

std::ostream &operator<<(std::ostream &os, JSON::IType &type);

# include "templates_methods/Array.tpp"
# include "templates_methods/Object.tpp"

#endif