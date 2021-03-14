#include <mlx.h>
#include "libs/mylib/ft_printf/ft_printf.h"
#include "libs/mylib/libft/libft.h"
#include "libs/mylib/cub3d/cub3d.h"

int     main(int argc, char *argv[])
{
	if (argc != 2 || !parse_settings(argv[1]))
		return (ERR);
	return (OK);
}
