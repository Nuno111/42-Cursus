/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:07:47 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/10 13:02:27 by ngregori         ###   ########.fr       */
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
	height = (game->cube_size / distance) * game->player.dtpp;
	return (height);
}

