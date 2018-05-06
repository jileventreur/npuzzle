#include "AStar.class.hpp"

size_t	AStar::estimate_distance(int xa, int ya, int xb, int yb)
{
	return (abs(xb - xa) + abs(yb - ya)); // manhattan distance 
}

size_t	AStar::heuristic(Node const &p)
{
	size_t total;
	size_t size;
	size_t case_value;

	size = p.get_dim();
	total = 0;
	for (size_t j = 0; j < size; ++j)
	{
		for (size_t i = 0; i < size; ++i)
		{
			case_value = p.get_case(i, j);
			// printf("point(%lu,%lu), value %lu(%lu, %lu) -> distance = %lu\n",
			// i,j, case_value, case_value % size, case_value / size, 
			// estimate_distance(i, j, case_value % size, case_value / size)
			// );
			total += estimate_distance(i, j, case_value % size, case_value / size);
		}
	}
	return (total);
}

template<typename T, typename priority_t>
struct PriorityQueue {
	typedef std::pair<priority_t, T> PQElement;
	std::priority_queue<PQElement, std::vector<PQElement>,
	std::greater<PQElement>> elements;

	inline bool empty() const 
	{
		return (elements.empty());
	}

	inline void put(T item, priority_t priority)
	{
		elements.emplace(priority, item);
	}

	T get() {
		T best_item = elements.top().second;
		elements.pop();
		return (best_item);
	}
};

void	AStar::search(Node *start)
{
	std::map<Node, Node> came_from;
	std::map<Node, double> cost_so_far;
	PriorityQueue<Node, double> Open_pq;
	Node next[MAX_NEIGHBORS];
	size_t max;

	Open_pq.put(*start, 0);
	came_from[*start] = *start;
	cost_so_far[*start] = 0;
	while (!Open_pq.empty()) 
	{
		Node current = Open_pq.get();
		// if (current == goal) Implement IsGoal for generic algorithm
		if (!this->heuristic(current))
		{
			printf("My job here is done\n");
			break;
		}
		max = current.get_neighbors(next);
		for (size_t i = 0; i < max; ++i)
		{
			// double new_cost = cost_so_far[current] + graph.cost(current, next[i]); // implement for generic algorithm
			double new_cost = cost_so_far[current] + 1;
			if (cost_so_far.find(next[i]) == cost_so_far.end() || new_cost < cost_so_far[next[i]])
			{
				cost_so_far[next[i]] = new_cost;
				double priority = new_cost + this->heuristic(next[i]);
				Open_pq.put(next[i], priority);
				came_from[next[i]] = current;
			}
		}
	}
	printf("END\n");
}	

/*
coplien form functions **********************************************************************************************************
*********************************************************************************************************************************
*/

AStar::AStar() {}
AStar::~AStar() {}
AStar &AStar::operator=(AStar const & rhs) {if (&rhs == this) {} return (*this);}
