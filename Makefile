CC = clang++
CFLAGS = -Werror -Wall -Wextra -std=c++14

NAME = npuzzle

DIR_SRC = ./srcs/
INCLUDES = 

FILES = main.cpp \
		Parser.class.cpp \
		ParserException.class.cpp \
		Puzzle.class.cpp \

SRC := $(addprefix $(DIR_SRC), $(FILES))

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re