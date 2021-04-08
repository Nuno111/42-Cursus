/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:07:47 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/07 11:34:00 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_wall_height(t_game *game, double distance_to_wall)
{
	double height;
	double	dist_to_proj_plane;

	distance_to_wall = (distance_to_wall / game->minimap_tile.size) * game->cube_size;
	dist_to_proj_plane = (game->settings.res->x / 2) / tan(game->player.fov_ang / 2);
	height = (game->cube_size / distance_to_wall) * (game->settings.res->y - game->player.circle.y)  * dist_to_proj_plane;
}
void	render_walls(t_game *game)
{
	printf("%s", game->settings.no);
}
