NAME = fillit
SRC = main.c
OBJ = $(SRC:.c=.o)
	all: 
		gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)
clean:
		rm -rf $(OBJ)
fclean: clean
		rm -rf $(NAME)
re: fclean all

.PHONY: make clean fclean re
