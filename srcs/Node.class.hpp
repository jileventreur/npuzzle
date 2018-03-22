#ifndef NODE_CLASS_HPP
#define NODE_CLASS_HPP
#include <utility>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include "IPuzzle.hpp"
#include "Puzzle.class.hpp"

class Node  {
public:
	Node(std::vector<int> data, size_t g, size_t h);
	Node(Node const &src);
	Node &operator=(const Node &);
	virtual ~Node(void);
	
	static bool compare(Node const &a, Node const &b);
	std::vector<int> get_data(void) const;
	size_t get_cost(void) const;
	size_t get_weight(void) const;

private:
	Node();
	std::vector<int> _data;
	size_t _cost;
	size_t _weight;
};
#endif