NAME = mylib.a

CC = gcc

CFLAGS =  -c -g -Wall -Werror -Wextra

LIB_FLAGS = -rcs

SRC0 = $(wildcard ft_printf/*.c)

DST0 = $(SRC:.c=.o)

SRC1 = $(wildcard libft/*.c)

DST1 = $(SRC1:.c=.o)

SRC2 = $(wildcard cub3d/*.c)

DST2 = $(SRC2:.c=.o)

all : $(NAME)

$(NAME) : $(DST0) $(DST1) $(DST2)
	ar $(LIB_FLAGS) $@ $^

ft_printf/%.o : ft_printf/%.c ft_printf/ft_printf.h
	$(CC) $(CFLAGS) $< -o $@

libft/%.o : libft/%.c libft/libft.h
	$(CC) $(CFLAGS) $< -o $@

cub3d/%.o : cub3d/%.c cub3d/cub3d.h
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -f $(DST0) $(DST1) $(DST2)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
