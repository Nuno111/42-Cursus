/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:34:11 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/22 12:03:59 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_tile(t_data *img, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put(img , x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	create_minimap(t_scene *settings, t_data *img)
{
	int x;
	int y;
	int color;

	x = 0;
	y = 0;
	while (settings->map[x])
	{
		y = 0;
		while (settings->map[x][y])
		{
			if (settings->map[x][y] == '1')
				color = 0x000080;
			else
				color = 0x00FF00;
			create_tile(img, y * 10, x * 10, color);
			y++;
		}
		x++;
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
