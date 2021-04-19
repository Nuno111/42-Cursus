/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:07:47 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/19 11:47:23 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	assign_wall_texture(t_game *game, t_ray ray)
{
	if (ray.hrzt_hit)
	{
		if (ray.facing_up)
			return(game->walls.no);
		else
			return(game->walls.so);
	}
	else
	{
		if (ray.facing_right)
			return(game->walls.ea);
		else
			return(game->walls.we);
	}
}

void	init_walls(t_game *game)
{
	game->walls.no.img = mlx_xpm_file_to_image(game->vars.mlx, game->settings.no, &game->walls.no.width, &game->walls.no.height);
	game->walls.ea.img = mlx_xpm_file_to_image(game->vars.mlx, game->settings.ea, &game->walls.ea.width, &game->walls.ea.height);
	game->walls.so.img = mlx_xpm_file_to_image(game->vars.mlx, game->settings.so, &game->walls.so.width, &game->walls.so.height);
	game->walls.we.img = mlx_xpm_file_to_image(game->vars.mlx, game->settings.we, &game->walls.we.width, &game->walls.we.height);
	game->walls.no.addr = mlx_get_data_addr(game->walls.no.img, &game->walls.no.bits_per_pixel, &game->walls.no.line_length, &game->walls.no.endian);
	game->walls.ea.addr = mlx_get_data_addr(game->walls.ea.img, &game->walls.ea.bits_per_pixel, &game->walls.ea.line_length, &game->walls.ea.endian);
	game->walls.so.addr = mlx_get_data_addr(game->walls.so.img, &game->walls.so.bits_per_pixel, &game->walls.so.line_length, &game->walls.so.endian);
	game->walls.we.addr = mlx_get_data_addr(game->walls.we.img, &game->walls.we.bits_per_pixel, &game->walls.we.line_length, &game->walls.we.endian);
}

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

