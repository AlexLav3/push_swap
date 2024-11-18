NAME = push_swap
CC = gcc -g
CFLAGS =
SOURCES = push_swap.c f_stack.c swap_functions.c push_rotate.c other.c rrr_functions.c \
utils.c r_calculations.c f_push_rot.c f_operations_2.c values_forbtoa.c sort_btoa.c
OBJECTS = $(SOURCES:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)
	@echo "fuck you push_swap"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
