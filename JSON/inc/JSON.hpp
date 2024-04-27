#ifndef JSON_HPP
# define JSON_HPP
# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <vector>

namespace JSON {
	class IType {
	};
	class Number : public IType {
		public:
			typedef double value_type;
			double value;
			Number();
			Number(std::ifstream &ifs);
			Number(std::string &filename);
			~Number(){};
	};
	class String : public IType {
		public:
			std::string value;
			String(std::ifstream &ifs);
			String(std::string &filename);
			~String(){};
	};
	// class Boolean : public IType {
	// 	public:
	// 		bool value;
	// 		bool parse(std::ifstream &ifs);
	// };
	// class Array : public IType {
	// 	public:
	// 		std::vector<IType> value;
	// 		std::vector<IType> parse(std::ifstream &ifs);
	// };
	// class Object : public IType {
	// 	public:
	// 		std::map<std::string, IType> value;
	// 		std::map<std::string, IType> parse(std::ifstream &ifs);
	// };
	// class Null : public IType {
	// 	public:
	// 		void *value;
	// 		void *parse(std::ifstream &ifs);
	// };
}

#endif