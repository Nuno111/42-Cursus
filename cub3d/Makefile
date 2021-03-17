NAME = cub3D

CC = gcc

CFLAGS =  -c -g -Wall -Werror -Wextra

LIB_FLAGS = -rcs

SRC0 = $(wildcard validate_settings/*.c)

DST0 = $(SRC0:.c=.o)

SRC1 = $(wildcard render_game/*.c)

DST1 = $(SRC1:.c=.o)

DEBUG = -fsanitize=addres

CUB3DLIB = libcub3d.a

all : libft $(NAME)

$(NAME): $(CUB3DLIB)
	$(CC) $(CFLAGS) $(DEBUG) cub3d.c $(CUB3DLIB) -lbsd -lmlx -lXext -lX11 -g

$(CUB3Dlib) : $(DST0) $(DST1)
	ar $(LIB_FLAGS) $@ $^

libft:
	cd libs/mylib && $(make)

clean :
	rm -f $(DST0) $(DST1)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
