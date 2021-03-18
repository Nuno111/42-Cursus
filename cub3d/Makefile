NAME = cub3D

CC = gcc

ERR_FLAGS = -Wall -Werror -Wextra

LIB_FLAGS = -rcs

DEBUG = -g -fsanitize=address

CUB3DLIB = libcub3d.a

MLXFLAGS = -lbsd -lmlx -lXext -lX11

DEP_FLAGS = -I. -Ilibs/mylib/ft_printf -Ilibs/mylib/libft

SRC0 = $(wildcard validate_settings/*.c)

DST0 = $(SRC0:.c=.o)

SRC1 = $(wildcard render_game/*.c)

DST1 = $(SRC1:.c=.o)

SRC2 = $(wildcard game_helpers/*.c)

DST2 = $(SRC2:.c=.o)

MYLIB = libs/mylib/mylib.a

all : create_mylib $(NAME)

$(NAME): $(CUB3DLIB)
	$(CC) $(ERR_FLAGS) $(DEBUG) cub3d.c $(CUB3DLIB) $(MYLIB) $(MLXFLAGS) $(DEP_FLAGS)

$(CUB3DLIB) : $(DST0) $(DST1) $(DST2)
	ar $(LIB_FLAGS) $@ $^

create_mylib:
	cd libs/mylib && $(MAKE)

validate_settings/%.o : validate_settings/%.c cub3d.h
	$(CC) $(ERR_FLAGS) -c $(DEP_FLAGS)  $< -o $@

render_game/%.o : render_game/%.c cub3d.h
	$(CC) $(ERR_FLAGS) -c $(DEP_FLAGS) $< -o $@

game_helpers/%.o : game_helpers/%.c cub3d.h
	$(CC) $(ERR_FLAGS) -c $(DEP_FLAGS) $< -o $@

clean :
	rm -f $(DST0) $(DST1)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
