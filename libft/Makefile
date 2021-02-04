NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = libft.h

OPT = -c

LIBOPT = ar rcs

# Matches all .c files.
SRC = ${wildcard *.c}

# Replaces all .c file names with .o
DST = ${SRC:.c=.o}

all : ${NAME}

${NAME}: $(DST)
	$(LIBOPT) $@ $^

%.o : %.c $(LIB)
	$(CC) $(OPT) $(CFLAGS) $<

clean :
	rm -f ${DST} *.so *.out

fclean : clean
	rm -f ${NAME}

re : fclean all

so:
	$(CC) -c $(CFLAGS) -fPIC $(SRC)
	gcc -shared -o libft.so $(DST)

.PHONY: all clean fclean re
