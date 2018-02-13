#ifndef PARSER_EXCEPTION_CLASS_HPP
# define PARSER_EXCEPTION_CLASS_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
class ParserException : public std::runtime_error
{
	public:
		ParserException(char const *message) throw();
		virtual const char* what() const throw();
	private:
		const char* _msg;
};
#endif