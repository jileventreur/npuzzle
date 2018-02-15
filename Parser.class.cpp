#include "Parser.class.hpp"
#include "ParserException.class.hpp"
#include <map>

Parser::Parser() {
	this->_dim = 0;
	this->_row = 0;
}
Parser::~Parser() {}

bool Parser::checkOptions(char c)
{
	if (c != '-')
	{
		return true;
	}
	return false;
}

void Parser::parseOptions(std::string options)
{
	for(std::string::iterator it = options.begin(); it != options.end(); ++it)
	{
		if (this->checkOptions(*it))
		{
	    	std::cout << *it << std::endl;
			this->_options.push_back(*it);
		}
	}
}

std::vector<char> Parser::getOptions()
{
	return (this->_options);
}

int Parser::getDim()
{
	return (this->_dim);
}

int Parser::getMax()
{
	return (this->_max);
}

std::vector<int> Parser::getPuzzle()
{
	return (this->good_puzzle);
}

int Parser::check_solvency()
{
	int inv_count = 0;
    for (int i = 0; i < this->_max; i++)
    {
        for (int j = i+1; j < this->_max; j++)
        {
             if (this->good_puzzle[j] && this->good_puzzle[i] &&  this->good_puzzle[i] > this->good_puzzle[j])
                inv_count++; 
        }
    }
    if (inv_count%2 == 0)
    	std::cout << "SOLVABLE" << std::endl;
    else
  		throw std::exception();
  	return (1);
}

int Parser::display_line(int j, int exp, bool reverse)
{
	if (!exp)
		return (j);
	int i = 0;
	int c = reverse ? this->_dim : 0;
	j = j * this->_dim;
		int get = 0;
	if (!reverse) {
		while (get != exp)
		{
			if (std::find(this->good_puzzle.begin(), this->good_puzzle.end(), this->puzzle[i + j]) == this->good_puzzle.end())
			{
				this->good_puzzle.push_back(this->puzzle[i + j]);
				++get;
			}
			++c;
			++i;
		}
			--c;
	}
	else
	{
		i = this->_dim - 1;
		while (get != exp)
		{
			if (std::find(this->good_puzzle.begin(), this->good_puzzle.end(), this->puzzle[i + j])  == this->good_puzzle.end())
			{
				this->good_puzzle.push_back(this->puzzle[i + j]);
				++get;
			}
			--c;
			--i;
		}
	}
	return (c);
}

int Parser::display_column(int j, int exp, bool reverse)
{
	if (!exp)
		return (j);
	int i = 0;
	int l = reverse ? this->_dim : 0;
	int get = 0;
	if (!reverse)
	{
		while (get != exp)
		{
			if (std::find(this->good_puzzle.begin(), this->good_puzzle.end(), this->puzzle[j + this->_dim * i])  == this->good_puzzle.end())
			{
				this->good_puzzle.push_back(this->puzzle[j + this->_dim * i]);
				++get;
			}
			++i;
			++l;
		}
			--l;
	}
	else
	{
		i = this->_dim - 1;
		while (get != exp)
		{
			if (std::find(this->good_puzzle.begin(), this->good_puzzle.end(), this->puzzle[j + this->_dim * i])  == this->good_puzzle.end())
			{
				this->good_puzzle.push_back(this->puzzle[j + this->_dim * i]);
				++get;
			}
			--i;
			--l;
		}
	}
	return (l);
}

void Parser::convert()
{
	int i = 0;
	bool reverse = false;
	int dm = this->_dim;
	while (this->good_puzzle.size() != this->_max) 
	{
		i = this->display_line(i, dm, reverse);
		--dm;
		i = this->display_column(i, dm, reverse);
		reverse = !reverse;
	}
}

void Parser::open_file(std::string file) {
	std::ifstream f(file);
	if (f.is_open())
	{
		this->read_file(&f);
	}
	else
		throw ParserException("Can't open this file. Sorry.");
}

int Parser::read_file(std::ifstream *f) {
	std::string buff;

	while (getline(*f, buff))
	{
		this->analyze(buff);
	}
	if (!this->_dim || !this->_row || !this->_max)
		throw ParserException("Problem");
	if (this->_row != this->_dim)
		throw ParserException("Doesn't respect dimension.");
	return (1);
}

std::string	Parser::remove_comment(std::string str)
{
	int has_comment;
	has_comment = str.find_first_of("#");
	std::string new_string = str;

	if (has_comment != std::string::npos)
	{
		new_string = str.substr(0, has_comment);
	}
	return (new_string);
}

int	Parser::add_line_to_puzzle(std::string str)
{
	static int i = 0;
	int nb;
    std::string buf;
    std::stringstream ss(str);
 	int dist =  std::distance(std::istream_iterator<std::string>(
                           std::istringstream(str) >> std::ws),
                           std::istream_iterator<std::string>());
 	if (dist != this->_dim)
 		throw ParserException("Doesn't respect dimension.");
    while (ss >> buf)
    {
    	if (!this->is_number(buf))
    		throw ParserException("Puzzle error - Not a number.");
		nb = std::stoi(buf,nullptr,10);
		if (nb >= this->_max || std::find(this->puzzle.begin(), this->puzzle.end(), nb) != this->puzzle.end())
			throw ParserException("Puzzle error configuration error.");
		this->puzzle.push_back(nb);
		++i;
    }
    return (1);
}

int Parser::analyze(std::string str)
{
	std::string new_string = this->remove_comment(str);
	if (!new_string.empty())
	{
		if (!this->_dim)
			this->setDim(new_string);
		else
		{
			this->add_line_to_puzzle(new_string);
			++this->_row;
		}
	}
	return (1);
}

void Parser::setDim(std::string str)
{
	int dim;
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	if (!this->is_number(str))
		throw ParserException("Please give a number for the dimension.");
	dim = std::stoi(str,nullptr,10);
	if (dim <= 2)
		throw ParserException("We don't accept dimension lower than 2.");
	this->_dim = dim;
	this->_max = dim * dim;
}

bool Parser::is_number(std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
