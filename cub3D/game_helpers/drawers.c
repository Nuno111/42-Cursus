/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:48:12 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/19 18:34:36 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_inner_circle(t_img *img, t_circle circle, int res_height)
{
	while (circle.radius > 0)
	{
		circle.radius--;
		draw_inner_circle(img, circle, res_height);
		draw_circle(img, circle, res_height);
	}
}

void	draw_line(t_img *img, t_line line, int res_height)
{
	int		i;
	int		x;
	int		y;
	double	dir_x;
	double	dir_y;

	dir_x = cos(line.direction);
	dir_y = sin(line.direction);
	i = -1;
	while (++i <= line.size)
	{
		x = dir_x * i + line.x;
		y = dir_y * i + line.y;
		img->addr[x + y * res_height] = line.color;
	}
}

void	draw_circle(t_img *img, t_circle circle, int res_height)
{
	int	x;
	int	y;

	while (circle.ang < 360)
	{
		x = circle.radius * cos(deg_to_rad(circle.ang)) + circle.x;
		y = circle.radius * sin(deg_to_rad(circle.ang)) + circle.y;
		img->addr[x + y * res_height] = circle.color;
		circle.ang++;
	}
}

void	draw_square(t_img *img, t_square square, int resolution_height)
{
	size_t	width;
	size_t	height;
	int		x;
	int		y;

	height = 0;
	while (height <= square.size)
	{
		width = 0;
		while (width <= square.size)
		{
			x = square.x + width;
			y = square.y + height;
			img->addr[x + y * resolution_height] = square.color;
			width++;
		}
		height++;
	}
}
