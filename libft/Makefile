NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
SOURCES = src/ft_atoi.c src/ft_bzero.c src/ft_isalnum.c src/ft_isalpha.c src/ft_isascii.c src/ft_isdigit.c \
src/ft_isprint.c src/ft_memchr.c src/ft_memcmp.c src/ft_memcpy.c  src/ft_memmove.c src/ft_memset.c src/ft_strchr.c \
src/ft_strlcpy.c src/ft_strlen.c src/ft_strncmp.c src/ft_strnstr.c src/ft_strrchr.c src/ft_tolower.c src/ft_toupper.c \
src/ft_split.c src/ft_putchar_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_putstr_fd.c src/ft_substr.c \
src/ft_calloc.c src/ft_strjoin.c src/ft_strtrim.c src/ft_strmapi.c src/ft_itoa.c src/ft_striteri.c src/ft_strdup.c src/ft_strlcat.c\
src/ft_c.c src/ft_chosehex.c src/ft_chosenbr.c src/ft_hexlower.c src/ft_hexupper.c src/ft_pointer.c src/ft_printf.c \
src/ft_putchar_onear.c src/ft_putchar.c src/ft_putnbr.c src/ft_putnewl.c src/ft_putstr.c 

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
