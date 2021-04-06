/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:07:47 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/06 21:57:19 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_walls(t_game *game)
{
	t_img n_wall;
	t_color	color;
	int y;
	int x;
	int posx;

	y = 0;
	n_wall.img = mlx_xpm_file_to_image(game->vars.mlx, game->settings.ea, &n_wall.width, &n_wall.height);
	n_wall.addr = mlx_get_data_addr(n_wall.img, &n_wall.bits_per_pixel, &n_wall.line_length, &n_wall.endian);
	printf("%d\n", n_wall.endian);
	while (y < n_wall.height)
	{
		posx = 0;
		x = 0;
		while (x < n_wall.width * 4)
		{
			if (n_wall.endian == 1)
			{
				color.t = n_wall.addr[(y * n_wall.line_length) + x];
				color.r = n_wall.addr[(y * n_wall.line_length) + x + 1];
				color.g = n_wall.addr[(y * n_wall.line_length) + x + 2];
				color.b = n_wall.addr[(y * n_wall.line_length) + x + 3];
			}
			else
			{
				color.t = n_wall.addr[(y * n_wall.line_length) + x + 3];
				color.r = n_wall.addr[(y * n_wall.line_length) + x + 2];
				color.g = n_wall.addr[(y * n_wall.line_length) + x + 1];
				color.b = n_wall.addr[(y * n_wall.line_length) + x];
			}
			color.trgb = create_trgb(color.t, color.r, color.g, color.b);
			my_mlx_pixel_put(&game->img, posx,y, color.trgb);
			posx++;
			x+= 4;
		}
		y++;
	}
}
