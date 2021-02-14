NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = libft.h

OPT = -c

LIBOPT = ar rcs

SRC = ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c\
ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putendl_fd.c\
ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memccpy.c ft_putnbr_fd.c ft_strlen.c\
ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c\
ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c\
		ft_strcat_bonus.c ft_isspace_bonus.c ft_strnew_bonus.c ft_freearrays_bonus.c\
		ft_strchrindex_bonus.c

DST = ${SRC:.c=.o}

DST_BONUS = ${BONUS:.c=.o}

${NAME}: $(DST)
	$(LIBOPT) $@ $^

bonus: ${DST} ${DST_BONUS}
	${LIBOPT} ${NAME} $^

%.o: %.c $(LIB)
	$(CC) $(OPT) $(CFLAGS) $<

all:${NAME}

clean:
	rm -f ${DST} ${DST_BONUS} *.so *.out

fclean: clean
	rm -f ${NAME}

re: fclean all

so:
	$(CC) -c $(CFLAGS) -fPIC $(SRC) $(BONUS)
	gcc -shared -o libft.so $(DST) $(DST_BONUS)

.PHONY: all clean fclean re
