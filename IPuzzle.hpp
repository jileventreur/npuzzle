#ifndef IPUZZLE
#define IPUZZLE
#define MAX_NEIGHBOR 4

enum edirection {up, down, left, right};

class IPuzzle {
public:
	virtual size_t get_case(size_t x, size_t y) const = 0;
	virtual size_t get_size(void) const = 0;
	virtual void get_blank(size_t &x, size_t &y) const = 0;
	virtual size_t get_neighbor(int & neighbor[MAX_NEIGHBOR]) const = 0;
	virtual size_t switch_neighbor(edirection const neighbor) const = 0;
	virtual std::string toString(void) const = 0;
	// virtual IPuzzle *toPuzzle(std::string const &) const = 0; // a voir

	virtual ~IPuzzle(void) {}
};
#endif