/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:29:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/29 13:38:42 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_minimap(t_scene *settings, t_game *game)
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
			draw_square(&game->img, settings, width * settings->tile_size.x, height * settings->tile_size.y, color);
			if (ft_strchr("NESW", settings->map[height][width]))
			init_player(game, settings, width * settings->tile_size.x, height * settings->tile_size.y);
			width++;
		}
		height++;
	}
}
