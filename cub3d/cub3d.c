#include <mlx.h>
#include "libs/mylib/ft_printf/ft_printf.h"
#include "libs/mylib/libft/libft.h"
#include "libs/mylib/cub3d/cub3d.h"

int     main(int argc, char *argv[])
{
    void    *mlx;
    void    *mlx_win;

	if (argc != 2 || !parse_name(argv[1]) || !parse_settings(argv[1]))
		return (ERR);
    mlx = mlx_init();
	if (!mlx)
		return (-1);
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    mlx_loop(mlx);
}
