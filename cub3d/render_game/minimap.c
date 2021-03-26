/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:29:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/26 21:51:49 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	draw_circle(t_data *img, t_scene *settings, t_player player, int posx, int posy)
{
	double x;
	double y;
	int color;
	double ang;

	ang = 0;
	color = 0xFFFFFF;
	while (ang < 360)
	{
		x = player.radius * cos(deg_to_rad(ang));
		y = player.radius * sin(deg_to_rad(ang));
		my_mlx_pixel_put(img, posx + x + (settings->tile_size.x / 2), posy + y + (settings->tile_size.y / 2), color);
		ang+= 0.1;
	}
}

static	void	init_player(t_data *img, t_scene *settings, int x, int y)
{
	t_player player;

	player.x = x;
	player.x = y;
	player.radius = settings->tile_size.x / 3; // size of circle needs to be adjsted later
	player.turn_dir = 0;
	player.walk_dir = 0;
	player.rotation_angle = M_PI / 2; //player facing position pi /2 90degree == North
	player.move_speed = 1;
	player.rotation_speed = 2 * (M_PI / 180);
	draw_circle(img, settings, player, x, y);
	printf("%s", settings->no);
}

static	void	draw_square(t_data *img, t_scene *settings, int x, int y, int color)
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
	settings->tile_size.x = (settings->res->x / settings->map_width);
	settings->tile_size.y = settings->tile_size.x;
	while (settings->map[height])
	{
		width = 0;
		while (settings->map[height][width])
		{
			if (ft_strchr("NESW", settings->map[height][width]))
				init_player(img, settings, width * settings->tile_size.x, height * settings->tile_size.y);
			else
			{
				if (settings->map[height][width] == '1')
					color = 0x000080;
				else if (settings->map[height][width] == '0')
					color = 0xFFFF00;
				else
					color = 0x000000;
				draw_square(img, settings, width * settings->tile_size.x, height * settings->tile_size.y, color);
			}
			width++;
		}
		height++;
	}
}
