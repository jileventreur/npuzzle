#ifndef PARSER_CLASS_HPP
# define PARSER_CLASS_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
class Parser {
public:
	Parser(void);
	Parser(const Parser&);
	~Parser(void);
	Parser &operator=(const Parser);
	void open_file(std::string file);
	int read_file(std::ifstream *f);
	int analyze(std::string str);
	std::string remove_comment(std::string str);
	int	add_line_to_puzzle(std::string str);
	void setDim(std::string str);
	bool is_number(std::string& s);
	void convert();
	int display_line(int j, int exp, bool reverse);
	int display_column(int j, int exp, bool reverse);
	int check_solvency();
	void parseOptions(std::string options); 
	bool checkOptions(char c);
	std::vector<int> getPuzzle();
	std::vector<char> getOptions();
	int getMax();
	int getDim();

private:
	int _row;
	int _max;
	int	_dim;
	std::vector<char> _options;
	std::vector<int> good_puzzle;
	std::vector<int> puzzle; //bientot en vecteur
};
#endif