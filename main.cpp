#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include "Parser.class.hpp"
#include "ParserException.class.hpp"

int main(int argc, char **argv) {
	int i = 1;
	Parser *parser = new Parser();
	std::string buf;
	//std::cout << argv[i] << std::endl;
	if (argc >= 3 && strncmp(argv[i], "--", 2) == 0)
	{
		parser->parseOptions(argv[i]);
		++i;
	}
	if (argc >= 2)
	{
		try
		{
			parser->open_file(argv[i]);
		}
		catch (ParserException &e)
		{
			std::cout << "PARSING EXCEPTION" << std::endl;
			std::cout << e.what() << std::endl;
			exit(0);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception standard" << std::endl;
		}
	}
	else
	{
		exit(0);
	}
	parser->convert();
	try {
		parser->check_solvency();
	} catch (std::exception &e) {
		std::cout << "UNSOLVABLE" << std::endl;
		exit(0);
	}
	delete parser;
	return (1);
}
