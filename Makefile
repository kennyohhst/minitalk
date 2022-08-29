GCC = cc
NAME = server client
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

client: client.o
	$(GCC) -o client client.o

server: server.o
	$(GCC) -o server server.o

client.o: client.c
	$(GCC) $(FLAGS) -c client.c -o client.o

server.o: server.c
	$(GCC) $(FLAGS) -c server.c -o server.o

clean:
	rm -f *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all