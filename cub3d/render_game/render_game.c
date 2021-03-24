/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:34:11 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/24 12:52:49 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_tile(t_data *img, t_scene *settings, int x, int y, int color)
{
	size_t width;
	size_t height;

	height = 0;
	while (height <= settings->tile_size.y)
	{
		width = 0;
		while (width <= settings->tile_size.x)
		{
			my_mlx_pixel_put(img , x + width, y + height, color);
			width++;
		}
		height++;
	}
}

void	create_minimap(t_scene *settings, t_data *img)
{
	int width;
	int height;
	int color;


	height = 0;
	settings->tile_size.x = settings->res->x / settings->map_width;
	settings->tile_size.y = settings->res->y / settings->map_size;
	while (settings->map[height])
	{
		width = 0;
		while (settings->map[height][width])
		{
			if (settings->map[height][width] == '1')
				color = 0x000080;
			else
				color = 0x00FF00;
			create_tile(img, settings, width * settings->tile_size.x, height * settings->tile_size.y, color);
			width++;
		}
		height++;
	}
}

void    render_game(t_scene *settings)
{
	t_data	img;
	t_vars var;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, settings->res->x, settings->res->y, "CUB3D");
	img.img = mlx_new_image(var.mlx, settings->res->x, settings->res->y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	create_minimap(settings, &img);
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_key_hook(var.win, handle_key_press, &var);
	mlx_loop(var.mlx);
}
