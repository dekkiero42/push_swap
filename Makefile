CC = cc
FLAGS = -Wall -g -Wextra -Werror
SRC = main.c
LIB_DIR = libft
LIB = $(LIB_DIR)/libft.a
NAME = push_swap
TEST_NUMBERS = "1312 31 4 3 23 -2147483648"
TEST_INPUT = 1312 2
100 = 37 92 14 68 55 81 6 49 100 23 71 9 64 58 1 76 33 87 41 19 95 52 28 73 60 12 90 4 66 45 83 17 98 31 7 70 56 39 26 85 63 11 47 99 21 75 2 59 34 88 16 79 43 94 8 61 27 51 97 20 72 5 84 40 65 29 93 10 57 80 48 36 18 86 54 3 69 44 96 25 62 15 82 32 91 13 67 74 35 78 22 53 46 24 89 30 77 42 50

all: $(NAME)

$(NAME):$(LIB) $(SRC)
	$(CC) $(FLAGS) $(SRC) -I$(LIB_DIR) $(LIB) -o $(NAME)
	
test: $(NAME)
	./$(NAME) $(100)


memory: $(NAME)
	valgrind  --leak-check=full ./$(NAME) $(TEST_INPUT)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re : fclean all 
