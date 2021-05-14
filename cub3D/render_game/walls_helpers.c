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
			return (game->txts.no);
		else
			return (game->txts.so);
	}
	else
	{
		if (ray.facing_right)
			return (game->txts.ea);
		else
			return (game->txts.we);
	}
}

void	calc_wall_dist(t_game *game, t_ray *ray)
{
	double	h_dist;
	double	v_dist;

	get_horizontal_intercection(game, ray);
	get_vertical_intercection(game, ray);
	if (ray->w_hrzt_hit)
		h_dist = get_dist(ray->line.x, ray->line.y, ray->w_hrzt_x, ray->w_hrzt_y);
	else
		h_dist = DBL_MAX;
	if (ray->w_vrtc_hit)
		v_dist = get_dist(ray->line.x, ray->line.y, ray->w_vrtc_x, ray->w_vrtc_y);
	else
		v_dist = DBL_MAX;
	if (h_dist < v_dist)
	{
		ray->w_vrtc_hit = false;
		ray->line.size = h_dist;
		ray->w_txt_pixel = ray->w_hrzt_x;
	}
	else
	{
		ray->w_hrzt_hit = false;
		ray->line.size = v_dist;
		ray->w_txt_pixel = ray->w_vrtc_y;
	}
}

double	get_wall_height(t_game *game, t_ray *ray)
{
	double height;
	double distance;
	double fishbowl_adjust;

	fishbowl_adjust = cos(ray->line.dir - game->player.rot_ang);
	distance = (ray->line.size / game->mmt.size) * game->cube_size * fishbowl_adjust;
	height = (game->cube_size / distance) * game->player.dtpp;
	return (height);
}

