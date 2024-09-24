NAME = libftpp.a
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -rf
AR = ar rcs
FLAGS = -Wall -Werror -Wextra -std=c++11 -g

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
