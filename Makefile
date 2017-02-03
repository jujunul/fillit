NAME = fillit

INC = -I./includes/ -I./libft/

SRC = main.c\
	  algo.c\
	  tetri_in_map.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror $(INC)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
			gcc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
			make -C libft/

clean:
			rm -rf $(OBJ)
			make -C libft/ clean

fclean: clean
			make -C ./libft/ fclean
			rm -rf $(NAME)

re: fclean all

.PHONY: make clean fclean re
