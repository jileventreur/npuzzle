#ifndef ASTAR_CLASS_HPP
#define ASTAR_CLASS_HPP
#include <utility>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include "IPuzzle.hpp"
#include "Puzzle.class.hpp"
#include "Node.class.hpp"

class AStar  {
public:
	void solve_puzzle(Puzzle *p);
	AStar();
	AStar(std::vector<int> AStar, size_t dim, size_t blank);
	virtual ~AStar(void);
	AStar &operator=(const AStar &);

private:
	size_t	estimate_distance(int xa, int ya, int xb, int yb);
	size_t	heuristic_estimate_cost(Puzzle *p);


};
#endif