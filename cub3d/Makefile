NAME = cub3D

CC = gcc

ERR_FLAGS = -Wall -Werror -Wextra

LIB_FLAGS = -rcs

DEBUG = -g -fsanitize=address

CUB3DLIB = libcub3d.a

MLXFLAGS = -lbsd -lmlx -lXext -lx11

LIB_DEP = $(shell find . -name *.h)

DEP_FLAGS = -Irender_game -Ivalidate_settings -Ihelpers -I. -Ilibs/mylib/ft_printf -Ilibs/mylib/libft

SRC0 = $(wildcard validate_settings/*.c)

DST0 = $(SRC0:.c=.o)

SRC1 = $(wildcard render_game/*.c)

DST1 = $(SRC1:.c=.o)

SRC2 = $(wildcard helpers/*.c)

DST2 = $(SRC2:.c=.o)

MYLIB = libs/mylib/mylib.a

all : create_mylib $(NAME)

$(NAME): $(CUB3DLIB)
	$(CC) $(CFLAGS) $(DEBUG) cub3d.c $(CUB3DLIB)

$(CUB3DLIB) : $(DST0) $(DST1) $(DST2)
	ar $(LIB_FLAGS) $@ $^

create_mylib:
	cd libs/mylib && $(MAKE)

validate_settings/%.o : validate_settings/%.c $(LIB_DEP)
	$(CC) $(CFLAGS) -c $(DEP_FLAGS)  $< $(MYLIB) -o $@

render_game/%.o : render_game/%.c $(LIB_DEP)
	$(CC) $(CFLAGS) -c $(DEP_FLAGS) $< $(MYLIB) -o $@

helpers/%.o : helpers/%.c $(LIB_DEP)
	$(CC) $(CFLAGS) -c $(DEP_FLAGS) $< $(MYLIB) -o $@

clean :
	rm -f $(DST0) $(DST1)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
