NAME = cub3D

MACNAME = cub3dmac

CC = gcc

ERR_FLAGS = -Wall -Wextra

LIB_FLAGS = -rcs

DEBUG_FLAGS = -g -fsanitize=address

CUB3DLIB = libcub3d.a

LINUXFLAGS = -lbsd -lmlx -lXext -lX11 -lm

MACFLAGS = -Llibs/macopengl/ -lmlx -framework OpenGL -framework AppKit -lm

DEP_FLAGS = -I. -Ilibs/libft/libft

LIBFT = libs/libft/libft.a

SRC0 = $(wildcard validate_settings/*.c)

DST0 = $(SRC0:.c=.o)

SRC1 = $(wildcard render_game/*.c)

DST1 = $(SRC1:.c=.o)

SRC2 = $(wildcard game_helpers/*.c)

DST2 = $(SRC2:.c=.o)

all : libft $(NAME)

macr : mac
	./cub3dmac maps/map.cub

mac : libft mlx $(MACNAME)

mlx :
	cd libs/macopengl && $(MAKE)

$(MACNAME) : $(CUB3DLIB)
	$(CC) $(ERR_FLAGS) $(DEBUG_FLAGS) cub3d.c $(CUB3DLIB) $(LIBFT) $(MACFLAGS) $(DEP_FLAGS) -o $(MACNAME)

$(NAME): $(CUB3DLIB)
	$(CC) $(ERR_FLAGS) $(DEBUG_FLAGS) cub3d.c $(CUB3DLIB) $(LIBFT) $(LINUXFLAGS) $(DEP_FLAGS) -o $(NAME)

$(CUB3DLIB) : $(DST0) $(DST1) $(DST2)
	ar $(LIB_FLAGS) $@ $^

libft:
	cd libs/libft && $(MAKE)

validate_settings/%.o : validate_settings/%.c cub3d.h
	$(CC) $(ERR_FLAGS) $(DEBUG_FLAGS) -c $(DEP_FLAGS)  $< -o $@

render_game/%.o : render_game/%.c cub3d.h
	$(CC) $(ERR_FLAGS) $(DEBUG_FLAGS) -c $(DEP_FLAGS) $< -o $@

game_helpers/%.o : game_helpers/%.c cub3d.h
	$(CC) $(ERR_FLAGS) $(DEBUG_FLAGS) -c $(DEP_FLAGS) $< -o $@

clean :
	rm -f $(DST0) $(DST1) $(DST2)

fclean : clean
	rm -rf $(NAME) $(CUB3DLIB) $(MACNAME) *.dSYM
	cd libs/libft && make fclean
	cd libs/macopengl && make clean

re : fclean all

.PHONY : all clean fclean re
