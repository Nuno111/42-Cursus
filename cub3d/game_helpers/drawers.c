/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:48:12 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/02 12:49:27 by ngregori         ###   ########.fr       */
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

void	draw_square(t_img *img, t_square square)
{
	size_t width;
	size_t height;

	height = 0;
	while (height <= square.size)
	{
		width = 0;
		while (width <= square.size)
		{
			my_mlx_pixel_put(img , square.x + width, square.y + height, square.color);
			width++;
		}
		height++;
	}
}
