#ifndef PUZZLE_CLASS_HPP
#define PUZZLE_CLASS_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>  
#include "IPuzzle.hpp"

class Puzzle : IPuzzle {
public:
							Puzzle();
							Puzzle(std::vector<int> puzzle, size_t dim, size_t blank);
							Puzzle(std::vector<int> puzzle, size_t dim);
	virtual					~Puzzle(void);
	Puzzle 					&operator=(const Puzzle &);
	virtual size_t			get_case(size_t x, size_t y) const;
	virtual size_t 			get_size(void) const;
	virtual void 			get_blank(size_t &x, size_t &y) const;
	virtual size_t 			get_neighbor(int neighbor[MAX_NEIGHBOR]) const;
	virtual size_t 			switch_neighbor(edirection const neighbor);
	virtual std::string 	toString(void) const;
	std::vector<int> 		getPuzzle();
	void		 			printPuzzle(void);

private:
	std::vector<int> 		_data;
	size_t 					_dim;
	size_t 					_blank;
};
#endif