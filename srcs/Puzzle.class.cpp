#include "Puzzle.class.hpp"
#include <algorithm>

Puzzle::Puzzle() {}
Puzzle::Puzzle(std::vector<int> puzzle, size_t dim, size_t blank) : 
_data(puzzle), _dim(dim), _blank(blank) {}
Puzzle::Puzzle(std::vector<int> puzzle, size_t dim) : _data(puzzle), _dim(dim)
{
	this->_blank = static_cast<size_t>(std::find(this->_data.begin(), this->_data.end(), 0) - this->_data.begin());
}

Puzzle::~Puzzle() {}
Puzzle &Puzzle::operator=(Puzzle const & rhs) 
{
	if (this == &rhs)
		return (*this);
	this->_data = rhs._data;
	this->_dim = rhs._dim;
	this->_blank = rhs._blank;
	return (*this);
}

size_t Puzzle::get_case(size_t x, size_t y) const 
{
	return (this->_data[x + (y * this->_dim)]);
};

size_t Puzzle::get_size(void) const {
	return (this->_dim);
};

void Puzzle::get_blank(size_t &x, size_t &y) const {
	x = (this->_blank % this->_dim);
	y = (this->_blank / this->_dim);
};

 //size_t Puzzle::get_neighbor(int & neighbor[MAX_NEIGHBOR]) const {};

//TU VEUX QUOI EN RETURN ?
//Switch directement dans le puzzle
 size_t Puzzle::switch_neighbor(edirection const neighbor) 
 {
 	size_t index = 0;

 	switch (neighbor)
 	{
 		case up:
 			index = this->_blank - this->_dim;
 			break;
		case down:
			index = this->_blank + this->_dim;
			break;
		case left:
			index = this->_blank - 1;
			break;
		case right:
			index = this->_blank + 1;
			break;
	}
	iter_swap(this->_data.begin() + this->_blank, this->_data.begin() + index);
	this->_blank = index;
 	return(index);
 };

//TU COMPTES UTILISER LES VALEURS DE RETOUR ??
//Renvoie -1 si le move n'est pas possible
 size_t Puzzle::get_neighbor(int neighbor[MAX_NEIGHBOR]) const
 {
 	//std::cout << this->_blank - this->_dim << std::endl;
	neighbor[up] = this->_blank / this->_dim != 0 ? this->_data[this->_blank - this->_dim] : -1;
	neighbor[down] = this->_blank / this->_dim != this->_dim - 1 ? this->_data[this->_blank + this->_dim] : -1;
	neighbor[left] = this->_blank % this->_dim != 0 ? this->_data[this->_blank - 1] : -1;
	neighbor[right] = this->_blank % this->_dim != this->_dim - 1 ? this->_data[this->_blank + 1] : -1;
 	return (1);
 }

 void		 Puzzle::printPuzzle(void) {
 	int i;

 	i = 0;
 	// std::cout << "________________________________" << std::endl;
    for(std::vector<int>::iterator it=this->_data.begin(); it!=this->_data.end(); ++it)
    {
        std::cout << *it << " ";
    	++i;
    	if (i % this->_dim == 0)
    		std::cout << std::endl;
    }
 	// std::cout << "________________________________" << std::endl;
 }

 std::string Puzzle::toString(void) const {
 	std::ostringstream oss;
    
    std::copy(this->_data.begin(), this->_data.end()-1,
        std::ostream_iterator<int>(oss, " "));
    oss << this->_data.back();
  return (oss.str());
 }

 std::vector<int> Puzzle::getPuzzle()
 {
 	return (this->_data);
 }