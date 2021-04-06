/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:07:47 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/05 21:18:27 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_walls(t_game *game)
{
	t_img n_wall;
	t_color	color;


	n_wall.img = mlx_xpm_file_to_image(game->vars.mlx, game->settings.no, &n_wall.width, &n_wall.height);
	n_wall.addr = mlx_get_data_addr(n_wall.img, &n_wall.bits_per_pixel, &n_wall.line_length, &n_wall.endian);
	int i = 0;
	while (i < n_wall.height)
	{
		int j = 0;
		while (j < n_wall.width)
		{
			if (n_wall.endian == 1)
			{
				color.t = n_wall.addr[(i * n_wall.line_length) + j];
				color.r = n_wall.addr[(i * n_wall.line_length) + j + 1];
				color.g = n_wall.addr[(i * n_wall.line_length) + j + 2];
				color.b = n_wall.addr[(i * n_wall.line_length) + j + 3];
			}
			else
			{
				color.t = n_wall.addr[(i * n_wall.line_length) + j + 3];
				color.r = n_wall.addr[(i * n_wall.line_length) + j + 2];
				color.g = n_wall.addr[(i * n_wall.line_length) + j + 1];
				color.b = n_wall.addr[(i * n_wall.line_length) + j];
			}
			color.trgb = create_trgb(color.t, color.r, color.g, color.b);
			printf("%d\n", color.trgb);
			my_mlx_pixel_put(&game->img, 300 + j, 300 + i, color.trgb);
			j += 4;
		}
		i++;
	}
}
