/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:48:12 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/28 13:58:53 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_inner_circle(t_img *img, t_circle circle)
{
	while (circle.radius > 0)
	{
		circle.radius--;
		draw_inner_circle(img, circle);
		draw_circle(img, circle);
	}
}

void	draw_line(t_img *img, t_line line)
{
	int i;

	i = 0;
	while (i <= line.size)
	{
		my_mlx_pixel_put(img, cos(line.direction) * i + line.x, sin(line.direction) * i + line.y, line.color);
		i++;
	}
}

void	draw_circle(t_img *img, t_circle circle)
{
	float	x;
	float	y;

	while (circle.ang < 360)
	{
		x = circle.radius * cos(deg_to_rad(circle.ang)) + circle.x;
		y = circle.radius * sin(deg_to_rad(circle.ang)) + circle.y;
		my_mlx_pixel_put(img, x, y, circle.color);
		circle.ang++;
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
