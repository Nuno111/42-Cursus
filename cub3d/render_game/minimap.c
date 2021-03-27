/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:29:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/27 19:53:59 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static	void	init_player(t_img *img, t_scene *settings, int x, int y)
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
	while (player.radius > 0)
	{
		draw_circle(img, settings, player, x, y);
		player.radius--;
	}
}

void	create_minimap(t_scene *settings, t_img *img)
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
