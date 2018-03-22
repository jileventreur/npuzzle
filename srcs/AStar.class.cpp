#include "AStar.class.hpp"

size_t	AStar::estimate_distance(int xa, int ya, int xb, int yb)
{
	return (abs(xb - xa) + abs(yb - ya)); // manhattan distance 
}

size_t	AStar::heuristic_estimate_cost(Puzzle *p)
{
	size_t total;
	size_t size;
	size_t case_value;

	size = p->get_size();
	total = 0;
	for (size_t j = 0; j < size; ++j)
	{
		for (size_t i = 0; i < size; ++i)
		{
			case_value = p->get_case(i, j);
			// printf("point(%lu,%lu), value %lu(%lu, %lu) -> distance = %lu\n",
			// i,j, case_value, case_value % size, case_value / size, 
			// estimate_distance(i, j, case_value % size, case_value / size)
			// );
			total += estimate_distance(i, j, case_value % size, case_value / size);
		}
	}
	return (total);
}

void	AStar::solve_puzzle(Puzzle *p)
{
	std::priority_queue<Node, std::vector<Node>, decltype(&Node::compare)> openSet(Node::compare);
	printf("heuristic cost : %lu\n", heuristic_estimate_cost(p));
	printf("puzzle %lu, vector %lu\n", sizeof(*p), sizeof(p->getPuzzle()));
}

/*
coplien form functions **********************************************************************************************************
*********************************************************************************************************************************
*/

AStar::AStar() {}
AStar::~AStar() {}
AStar &AStar::operator=(AStar const & rhs) {if (&rhs == this) {} return (*this);}
