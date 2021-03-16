all:
	cd libs/mylib && make
	gcc -fsanitize=address -Wall -Wextra cub3d.c validate_settings/*.c libs/mylib/mylib.a -lbsd -lmlx -lXext -lX11 -g
