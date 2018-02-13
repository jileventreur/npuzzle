#include "Parser.class.hpp"
#include "ParserException.class.hpp"
#include <map>

Parser::Parser() {
	this->_dim = 0;
}
Parser::~Parser() {}


int Parser::display_line(int j, int exp, bool reverse)
{
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
				std::cout << this->puzzle[i + j] << " ";
				++get;
			}
			++c;++i;
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
				std::cout << this->puzzle[i + j] << " ";
				++get;
			}
			--c;--i;
		}
	}
	return (c);
}

int Parser::display_column(int j, int exp, bool reverse)
{
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
				std::cout << this->puzzle[j + this->_dim * i] << " ";
				++get;
			}
			++i;++l;
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
				std::cout << this->puzzle[j + this->_dim * i] << " ";
				++get;
			}
			--i;--l;
		}
	}
	return (l);
}

void Parser::convert()
{
	std::map<int, int>::iterator it;
	std::vector<int>::iterator vit;
	std::cout << "Avant Convert" << std::endl;
	int i = 0;
	for(it = this->puzzle.begin() ; it != this->puzzle.end() ; ++it)
	{
		std::cout << it->second << " ";
		++i;
		if (i%this->_dim == 0)
			std::cout << std::endl;
	}
	std::cout << "_______________________________" << std::endl;;


	bool reverse = false;
	i = 0;
	int v = 0;
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
		std::cout << "C'est ouvert" << std::endl;
		this->read_file(&f);
	}
	else
		std::cout << "C'est fermé" << std::endl;
}

int Parser::read_file(std::ifstream *f) {
	std::string buff;

	while (getline(*f, buff))
	{
		this->analyze(buff);
	}
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
 	{
 		throw ParserException("Ne respecte pas la bonne dimension");
 	}
    while (ss >> buf)
    {
    	if (!this->is_number(buf))
    		throw ParserException("Pas un nombre");
		nb = std::stoi(buf,nullptr,10);
		if (nb >= this->_max)
		{
			throw ParserException("Nombre trop grand");
		}
		this->puzzle[i]= nb;
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
		}
	}
	return (1);
}

void Parser::setDim(std::string str)
{
	int dim;
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	if (!this->is_number(str))
	{
		throw ParserException("Pas une bonne dimension");
	}
	dim = std::stoi(str,nullptr,10);
	if (dim <= 2)
		throw ParserException("Dimension trop petite");
	this->_dim = dim;
	this->_max = dim * dim;
}

bool Parser::is_number(std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
