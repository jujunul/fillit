NAME = fillit

INC = -I./libft/

SRC = 	algo.c \
		ft_check.c \
		ft_error.c \
		ft_parcing.c \
		main.c \
		tetri_in_map.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror $(INC)

all: $(NAME) 

$(NAME): $(LIBFT) $(OBJ)
		gcc $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJ)

$(LIBFT):
		make -C libft/

clean:
		rm -rf $(OBJ)
		make -C libft/ clean

fclean: clean
		make -C ./libft/ fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: make clean fclean re all
