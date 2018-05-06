// #include "Node.class.hpp"

// Node::~Node(void) {}
// Node::Node(void) {}
// Node::Node(Node const &src)  {*this = src;}

// Node::Node(std::vector<int> data, size_t cost)
// : _data(data), _cost(cost) {}

// Node	&Node::operator=(Node const &rhs) 
// {
// 	if (this == &rhs)
// 		return (*this);
// 	this->_data = rhs._data;
// 	this->_cost = rhs._cost;
// 	// this->_weight = rhs._weight;
// 	return (*this);
// }

// std::vector<int> Node::get_data(void) const {return (this->_data);}
// size_t Node::get_cost(void) const {return (this->_cost);}
// // size_t Node::get_weight(void) const {return (this->_weight);}

// bool Node::compare(Node const &a, Node const &b)
// {
// 	return (a._cost > b._cost);
// }