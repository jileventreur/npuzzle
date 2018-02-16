class IPuzzle {
public:
	virtual size_t get_case(size_t x, size_t y) const = 0;
	virtual size_t get_size(void) const = 0;
	virtual size_t get_blank(void) const = 0;
	virtual void move_up(void) = 0;
	virtual void move_down(void) = 0;
	virtual void move_left(void) = 0;
	virtual void move_right(void) = 0;
	virtual std::string toString(void) const = 0;

	virtual ~IPuzzle(void) {}
};