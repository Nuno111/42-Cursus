NAME = mylib.a

CC = gcc

CFLAGS =  -c -g -Wall -Werror -Wextra

LIB_FLAGS = -rcs

SRC0 = $(wildcard ft_printf/*.c)

DST0 = $(SRC0:.c=.o)

SRC1 = $(wildcard libft/*.c)

DST1 = $(SRC1:.c=.o)

all : $(NAME)

$(NAME) : $(DST0) $(DST1) $(DST2)
	ar $(LIB_FLAGS) $@ $^

ft_printf/%.o : ft_printf/%.c ft_printf/ft_printf.h
	$(CC) $(CFLAGS) $< -o $@

libft/%.o : libft/%.c libft/libft.h
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -f $(DST0) $(DST1)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
