CC = cc
FLAGS = -Wall -g -Wextra -Werror
HEADER = push_swamp.h
SRC = main.c utils.c parsing.c sorting.c stack_ops.c target_price.c algorithm.c
OBJ = $(SRC:.c=.o)
LIB_DIR = libft
LIB = $(LIB_DIR)/libft.a
NAME = push_swap
100 = "18556 13454 15889 -16614 978 17582 -14189 4795 -8679 -21296 -4220 1308 5580 2344 -20304 -15094 625 21127 13861 -14233 4635 9612 -8850 1287 20232 14519 -6146 -17538 8350 2649 789 -17599 -7957 -19771 -11961 10573 -21041 20216 16570 1259 -6626 7736 -2047 13352 -21267 -8753 -3973 -11234 -11639 19746 5357 -12286 21093 9846 -7807 13923 19663 -15772 16305 2045 8825 3849 1319 1856 -20274 16765 10689 -19604 -5252 -20164 6505 -3394 -20587 -14582 7555 -8245 -1934 -19927 8984 -7264 -18091 -14520 -2487 12887 6275 11875 17317 -12416 11456 -8028 -18751 -21524 15110 8467 9258 -15207 -14919 -3632 -12793 -7691"
                                

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -I$(LIB_DIR) $(LIB) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -I$(LIB_DIR) -c $< -o $@
	
test: $(NAME)
	./$(NAME) $(100)

memory: $(NAME)
	valgrind  --leak-check=full ./$(NAME) $(100)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re : fclean all 
