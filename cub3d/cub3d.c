#include <mlx.h>
#include "libs/mylib/ft_printf/ft_printf.h"
#include "libs/mylib/libft/libft.h"
#include "libs/mylib/cub3d/cub3d.h"

void			error_and_exit(t_scene *settings, char *error_log)
{
	printf("%s.\n", error_log);
	free_settings(settings);
	exit(ERR);
}

static	void	init_settings(t_scene *settings)
{
	settings->res = NULL;
	settings->no = NULL;
	settings->so = NULL;
	settings->we = NULL;
	settings->ea = NULL;
	settings->sprite = NULL;
	settings->floor = NULL;
	settings->ceil = NULL;
	settings->tmp_map = NULL;
	settings->map = NULL;
	settings->valid = true;
}

void	free_settings(t_scene *settings)
{
	if (settings->res)
		free(settings->res);
	if (settings->no)
		free(settings->no);
	if (settings->so)
		free(settings->so);
	if (settings->we)
		free(settings->we);
	if (settings->ea)
		free(settings->ea);
	if (settings->sprite)
		free(settings->sprite);
	if (settings->floor)
		free(settings->floor);
	if (settings->ceil)
		free(settings->ceil);
	if (settings->tmp_map)
		ft_free_list(&settings->tmp_map);
	if (settings->map)
		ft_freearrays(settings->map);
}

int     main(int argc, char *argv[])
{
	t_scene settings;

	init_settings(&settings);
	if (argc != 2)
		error_and_exit(&settings, "Two arguments needed");
	parse_settings(&settings, argv[1]);
	free_settings(&settings);
	printf("ok");
	return (OK);
}
