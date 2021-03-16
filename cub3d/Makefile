all:
	cd libs/mylib && make
	gcc -fsanitize=address -Wall -Wextra -Werror cub3d.c validate_settings/*.c render_game/*.c libs/mylib/mylib.a -lbsd -lmlx -lXext -lX11 -g
