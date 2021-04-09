/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:07:47 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/09 17:44:42 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_wall_height(t_game *game, t_ray *ray)
{
	double height;
	double distance;
	double fishbowl_adjust;

	fishbowl_adjust = cos(ray->line.direction - game->player.rotation_angle);
	distance = (ray->line.size / game->minimap_tile.size) * game->cube_size * fishbowl_adjust;
	height = (game->cube_size / distance) * game->dtpp;
	return (height);
}

void	render_walls(t_game *game)
{
	int i;
	t_line line;

	i = 0;
	while (i < game->player.num_rays)
	{
		line.color = 0xffffff;
		line.direction = (M_PI / 2);
		line.size = get_wall_height(game, game->player.rays[i]);
		line.x = i;
		line.y = (game->settings.res->y / 2) - (line.size / 2);
		if (line.y < 0)
			line.y = 0;
		if (line.size > game->settings.res->y)
			line.size = game->settings.res->y;
		printf("%f\n", line.y);
		printf("%f\n", line.y);
		draw_line(&game->main_img, line);
		i++;
	}
}
