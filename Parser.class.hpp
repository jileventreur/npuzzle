#ifndef PARSER_CLASS_HPP
# define PARSER_CLASS_HPP
# include "Puzzle.class.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
class Parser {
public:
							Parser(void);
							Parser(const Parser&);
							~Parser(void);
	Parser 					&operator=(const Parser);
	Puzzle					*getPuzzle(std::string file);
	std::vector<char> 		getOptions(std::string options);

private:
	int 					analyze(std::string str);
	std::string 			remove_comment(std::string str);
	int						add_line_to_puzzle(std::string str);
	bool 					is_number(std::string& s);
	void 					convert();
	int 					display_line(int j, int exp, bool reverse);
	int 					display_column(int j, int exp, bool reverse);
	int 					check_solvency();
	void 					parseOptions(std::string options); 
	bool 					checkOptions(char c);
	void 					setDim(std::string str);
	void					add_to_the_row_puzzle(size_t tile_number);
	size_t					_blank;
	int 					_row;
	int 					_max;
	int						_dim;
	std::vector<char> 		_options;
	std::vector<int> 		_good_puzzle;
	std::vector<int> 		_puzzle;
};
#endif