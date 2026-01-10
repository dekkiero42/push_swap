CC = cc
FLAGS = -Wall -g -Wextra -Werror
SRC = main.c
LIB_DIR = libft
LIB = $(LIB_DIR)/libft.a
NAME = push_swap
TEST_NUMBERS = "1312 31 4 3 23 -2147483648"
TEST_INPUT = 1312 31 4 3 23 -2147483648

all: $(NAME)

$(NAME):$(LIB) $(SRC)
	$(CC) $(FLAGS) $(SRC) -I$(LIB_DIR) $(LIB) -o $(NAME)
	
test: $(NAME)
	./$(NAME) $(TEST_INPUT)


memory: $(NAME)
	valgrind  --leak-check=full ./$(NAME) $(TEST_NUMBERS)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re : fclean all 
