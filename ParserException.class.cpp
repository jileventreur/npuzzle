#include "ParserException.class.hpp"

	ParserException::ParserException(char const *message) throw() : std::runtime_error(message) 
	{
	}
	const char* ParserException::what() const throw()
	{	
		return runtime_error::what();
	}
