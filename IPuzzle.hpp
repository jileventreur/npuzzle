class IPuzzle {
public:
	virtual int get_case(int x, int y) const = 0;
	virtual void moove_up(void) = 0;
	virtual void moove_down(void) = 0;
	virtual void moove_left(void) = 0;
	virtual void moove_right(void) = 0;
	virtual std::string toString(void) const = 0;

	virtual ~IPuzzle(void) {}
};