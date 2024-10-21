NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
SOURCES = 

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

bonus:$(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

re: fclean all
