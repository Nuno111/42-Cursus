/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:48:12 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/27 19:53:53 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_circle(t_img *img, t_scene *settings, t_player player, int posx, int posy)
{
	int x;
	int y;
	int color;
	int ang;

	ang = 0;
	color = 0x7F0000;
	while (ang < 360)
	{
		x = player.radius * cos(deg_to_rad(ang));
		y = player.radius * sin(deg_to_rad(ang));
		my_mlx_pixel_put(img, posx + x + settings->tile_size.x / 2 , posy + y + settings->tile_size.x / 2, color);
		ang += 1;
	}
}

void	draw_square(t_img *img, t_scene *settings, int x, int y, int color)
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
