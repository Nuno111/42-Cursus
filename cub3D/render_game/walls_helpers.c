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
	if (ray.w_hrzt_hit)
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

void	calc_wall_dist(t_game *game, t_ray *ray)
{
	double hrzt_dist;
	double vrtc_dist;

	get_horizontal_intercection(game, ray, true);
	get_vertical_intercection(game, ray, true);
	if (ray->w_hrzt_hit)
		hrzt_dist = get_distance(ray->line.x, ray->line.y, ray->w_hrzt_x, ray->w_hrzt_y);
	else
		hrzt_dist = DBL_MAX;
	if (ray->w_vrtc_hit)
		vrtc_dist = get_distance(ray->line.x, ray->line.y, ray->w_vrtc_x, ray->w_vrtc_y);
	else
		vrtc_dist = DBL_MAX;
	if (hrzt_dist < vrtc_dist)
	{
		ray->w_vrtc_hit = false;
		ray->line.size = hrzt_dist;
		ray->w_txt_pixel = ray->w_hrzt_x;
	}
	else
	{
		ray->w_hrzt_hit = false;
		ray->line.size = vrtc_dist;
		ray->w_txt_pixel = ray->w_vrtc_y;
	}
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

