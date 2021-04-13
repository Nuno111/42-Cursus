/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:07:47 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/13 11:04:18 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	choose_wall_textures(t_game *game, t_ray *ray)
{
	if (ray->hrzt_hit)
	{
		if (ray->facing_up)
			ray->texture = game->wall.no.img;
		else
			ray->texture = game->wall.so.img;
	}
	else
	{
		if (ray->facing_right)
			ray->texture = game->wall.ea.img;
		else
			ray->texture = game->wall.we.img;
	}
}

void	init_walls(t_game *game)
{
	game->wall.no.img = mlx_xpm_file_to_image(game->vars.mlx, game->settings.no, &game->wall.no.width, &game->wall.no.height);
	game->wall.ea.img = mlx_xpm_file_to_image(game->vars.mlx, game->settings.ea, &game->wall.ea.width, &game->wall.ea.height);
	game->wall.so.img = mlx_xpm_file_to_image(game->vars.mlx, game->settings.so, &game->wall.so.width, &game->wall.so.height);
	game->wall.we.img = mlx_xpm_file_to_image(game->vars.mlx, game->settings.we, &game->wall.we.width, &game->wall.we.height);
	game->wall.no.addr = mlx_get_data_addr(game->wall.no.img, &game->wall.no.bits_per_pixel, &game->wall.no.line_length, &game->wall.no.endian);
	game->wall.ea.addr = mlx_get_data_addr(game->wall.ea.img, &game->wall.ea.bits_per_pixel, &game->wall.ea.line_length, &game->wall.ea.endian);
	game->wall.so.addr = mlx_get_data_addr(game->wall.so.img, &game->wall.so.bits_per_pixel, &game->wall.so.line_length, &game->wall.so.endian);
	game->wall.we.addr = mlx_get_data_addr(game->wall.we.img, &game->wall.we.bits_per_pixel, &game->wall.we.line_length, &game->wall.we.endian);
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

