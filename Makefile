CC = cc
FLAGS = -Wall -g -Wextra -Werror
SRC = main.c
LIB_DIR = libft
LIB = $(LIB_DIR)/libft.a
NAME = push_swap
TEST_NUMBERS =  5 6 2 3 7 8 9 1 4
TEST_INPUT = 1312 2
100 = 37 92 14 68 55 81 6 49 100 23 71 9 64 58 1 76 33 87 41 19 95 52 28 73 60 12 90 4 66 45 83 17 98 31 7 70 56 39 26 85 63 11 47 99 21 75 2 59 34 88 16 79 43 94 8 61 27 51 97 20 72 5 84 40 65 29 93 10 57 80 48 36 18 86 54 3 69 44 96 25 62 15 82 32 91 13 67 74 35 78 22 53 46 24 89 30 77 42 50

all: $(NAME)

$(NAME):$(LIB) $(SRC)
	$(CC) $(FLAGS) $(SRC) -I$(LIB_DIR) $(LIB) -o $(NAME)
	
test: $(NAME)
	./$(NAME) $(100)

test1: $(NAME)
	@echo "Test 1: 20 random elements - Set 1"
	./$(NAME) 47 82 15 63 28 91 53 11 74 36 89 22 68 4 77 45 59 19 86 31

test2: $(NAME)
	@echo "Test 2: 20 random elements - Set 2"
	./$(NAME) 73 18 64 39 12 87 51 76 25 94 6 58 41 20 79 33 67 9 55 43

test3: $(NAME)
	@echo "Test 3: 20 random elements - Set 3"
	./$(NAME) 84 27 62 14 96 37 70 48 21 66 8 52 35 78 44 61 29 13 72 57

test4: $(NAME)
	@echo "Test 4: 20 random elements - Set 4"
	./$(NAME) 65 32 88 17 50 75 26 69 7 54 40 23 81 46 60 11 30 77 19 92

test5: $(NAME)
	@echo "Test 5: 20 random elements - Set 5"
	./$(NAME) 38 71 24 85 16 99 34 68 9 56 42 20 80 47 63 5 59 28 74 12

test6: $(NAME)
	@echo "Test 6: 20 random elements - Set 6"
	./$(NAME) 51 10 76 39 64 22 97 18 61 35 87 27 73 52 41 14 69 6 84 58

test7: $(NAME)
	@echo "Test 7: 20 random elements - Set 7"
	./$(NAME) 45 29 72 8 55 40 67 19 81 31 60 11 77 46 25 88 32 65 17 70

test8: $(NAME)
	@echo "Test 8: 20 random elements with negatives"
	./$(NAME) -42 37 -18 64 -56 29 71 -12 48 63 -35 22 90 -7 54 76 -43 33 21 85

test9: $(NAME)
	@echo "Test 9: 20 random elements - Set 9"
	./$(NAME) 98 16 50 75 -9 66 26 43 57 13 36 82 4 61 47 20 72 59 28 69

test10: $(NAME)
	@echo "Test 10: 20 random elements - Set 10"
	./$(NAME) 53 41 87 9 24 68 38 12 85 64 39 71 18 99 27 76 14 56 58 22

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
