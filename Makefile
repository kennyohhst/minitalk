NAME = minitalk.a
FLAGS = -Wall -Werror -Wextra
SRC = server.c
HEAD = minitalk.h
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ):
	gcc -c $(FLAGS) $(SRC)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	
.PHONY: clean fclean re all