/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:29:13 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/22 13:50:00 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	bool	is_closer_to_player(t_ray *ray, t_intercect intercect)
{
	double dist;

	dist = get_distance(ray->line.x, ray->line.y, intercect.x, intercect.y);
	if (dist < ray->line.size)
	{
		printf("wall distance %f: sprite distance: %f\n", ray->line.size, dist);
		return (true);
	}
	return (false);
}
void		did_ray_hit_sprite(t_game *game, t_ray *ray, t_intercect intercect, bool hrzt)
{
	while (intercect.x < game->settings.width && intercect.y < game->settings.height &&
			intercect.x > 0 && intercect.y > 0)
	{
		if (is_sprite(intercect.x, intercect.y, game) && is_closer_to_player(ray, intercect))
		{
			if (hrzt)
			{
				ray->s_hrzt_hit = true;
				ray->s_hrzt_x = intercect.x;
				ray->s_hrzt_y = intercect.y;
			}
			else
			{
				ray->s_vrtc_hit = true;
				ray->s_vrtc_x = intercect.x;
				ray->s_vrtc_y = intercect.y;
			}
			return ;
		}
		else
		{
			intercect.x += intercect.x_step;
			intercect.y += intercect.y_step;
		}
	}
}
void	calc_sprite_dist(t_game *game, t_ray *ray)
{
	double hrzt_dist;
	double vrtc_dist;

	get_horizontal_intercection(game, ray, false);
	/*
	get_vertical_intercection(game, ray, false);
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
	*/
}