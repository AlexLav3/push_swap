NAME = push_swap.a
CFLAGS = -Wall -Werror -Wextra
SOURCES = push_swap.c f_stack.c f_stack.c swap_functions.c f_rp2.c other.c

OBJECTS = $(SOURCES:.c=.o)

all:${NAME} ${OBJECTS}

${NAME} : ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f ${NAME}

re: fclean all
