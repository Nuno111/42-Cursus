/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txts_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:07:47 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/22 12:38:24 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	assign_wall_texture(t_game *game, t_ray ray)
{
	if (ray.hrzt_hit)
	{
		if (ray.facing_up)
			return(game->txts.no);
		else
			return(game->txts.so);
	}
	else
	{
		if (ray.facing_right)
			return(game->txts.ea);
		else
			return(game->txts.we);
	}
}

void	init_txts(t_game *game)
{
	game->txts.no.img = mlx_xpm_file_to_image(game->mlx, game->settings.no, &game->txts.no.width, &game->txts.no.height);
	game->txts.ea.img = mlx_xpm_file_to_image(game->mlx, game->settings.ea, &game->txts.ea.width, &game->txts.ea.height);
	game->txts.so.img = mlx_xpm_file_to_image(game->mlx, game->settings.so, &game->txts.so.width, &game->txts.so.height);
	game->txts.we.img = mlx_xpm_file_to_image(game->mlx, game->settings.we, &game->txts.we.width, &game->txts.we.height);
	game->txts.no.addr = (int *)mlx_get_data_addr(game->txts.no.img, &game->txts.no.bits_per_pixel, &game->txts.no.line_length, &game->txts.no.endian);
	game->txts.ea.addr = (int *)mlx_get_data_addr(game->txts.ea.img, &game->txts.ea.bits_per_pixel, &game->txts.ea.line_length, &game->txts.ea.endian);
	game->txts.so.addr = (int *)mlx_get_data_addr(game->txts.so.img, &game->txts.so.bits_per_pixel, &game->txts.so.line_length, &game->txts.so.endian);
	game->txts.we.addr = (int *)mlx_get_data_addr(game->txts.we.img, &game->txts.we.bits_per_pixel, &game->txts.we.line_length, &game->txts.we.endian);
}

double	get_wall_height(t_game *game, t_ray *ray)
{
	double height;
	double distance;
	double fishbowl_adjust;

	fishbowl_adjust = cos(ray->line.dir - game->player.rot_ang);
	distance = (ray->line.size / game->minimap_tile.size) * game->cube_size * fishbowl_adjust;
	height = (game->cube_size / distance) * game->player.dtpp;
	return (height);
}

