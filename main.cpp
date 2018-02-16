#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include "Parser.class.hpp"
#include "ParserException.class.hpp"

int main(int argc, char **argv) {
	int i = 1;
	std::vector<char> options;
	Parser *parser = new Parser();
	Puzzle *pz;
	int salut[4] = {0,0,0,0};
	size_t x;
	size_t y;
	if (argc >= 3 && strncmp(argv[i], "--", 2) == 0)
	{
		options = parser->getOptions(argv[i]);
		++i;
	}
	if (argc >= 2)
	{
		try
		{
			pz = parser->getPuzzle(argv[i]);
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
	delete pz;
	delete parser;
	return (1);
}
