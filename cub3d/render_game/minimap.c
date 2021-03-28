/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:29:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/28 13:59:18 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static	void	init_player(t_img *img, t_scene *settings, int x, int y)
{
	t_player player;

	player.circle.x = x + settings->tile_size.x / 2.0;
	player.circle.y = y + settings->tile_size.x / 2.0;
	player.circle.radius = settings->tile_size.x / 4.0;
	player.circle.color = 0x7F0000;
	player.circle.ang = 0;
	player.turn_dir = 0;
	player.walk_dir = 0;
	player.rotation_angle = 0;
	player.move_speed = 1;
	player.rotation_speed = 2 * (M_PI / 180);
	player.line.x = player.circle.x;
	player.line.y = player.circle.y;
	player.line.color = 0x008000;
	player.line.direction = player.rotation_angle;
	player.line.size = player.circle.radius * 2;
	player.line.thickness = 10;
	draw_circle(img, player.circle);
	draw_inner_circle(img, player.circle);
	draw_line(img, player.line);
}

void	create_minimap(t_scene *settings, t_img *img)
{
	int width;
	int height;
	int color;


	height = 0;
	settings->tile_size.x = (settings->res->x / settings->map_width) / 4;
	settings->tile_size.y = settings->tile_size.x;
	while (settings->map[height])
	{
		width = 0;
		while (settings->map[height][width])
		{
			if (settings->map[height][width] == '1')
				color = 0x000080;
			else if (settings->map[height][width] == '0' || ft_strchr("NESW", settings->map[height][width]))
				color = 0xFFFF00;
			else
				color = 0x000000;
			draw_square(img, settings, width * settings->tile_size.x, height * settings->tile_size.y, color);
			if (ft_strchr("NESW", settings->map[height][width]))
			init_player(img, settings, width * settings->tile_size.x, height * settings->tile_size.y);
			width++;
		}
		height++;
	}
}
