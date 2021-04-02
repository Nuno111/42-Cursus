/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:39:24 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/02 13:46:12 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		get_distance(t_ray ray)
{
	double distance;

	distance = (ray.wall_hit_x - ray.ray.x) * (ray.wall_hit_x - ray.ray.x) +
				(ray.wall_hit_y - ray.ray.y) * (ray.wall_hit_y - ray.ray.y);
	return (sqrt(distance));
}

double		normalize_angle(double ray_ang)
{
	ray_ang = fmod(ray_ang, 2 * M_PI);
	if (ray_ang < 0)
		ray_ang += (2 * M_PI);
	return (ray_ang);
}

void		get_horizontal_intercection(t_game *game, t_ray *ray)
{
	double x_intercect;
	double y_intercect;
	double x_step;
	double y_step;

	y_intercect = floor(ray->ray.y / game->settings.tile_size.y) * game->settings.tile_size.y;
	x_intercect = ray->ray.x + (y_intercect - ray->ray.y) / tan(ray->ray.direction);
	if (!ray->facing_up)
		y_intercect += game->settings.tile_size.y;
	y_step = game->settings.tile_size.y;
	if (ray->facing_up)
		y_step *= -1;
	x_step = game->settings.tile_size.x / tan(ray->ray.direction);
	if (!ray->facing_right && x_step > 0)
		x_step *= -1;
	if (ray->facing_right && x_step < 0)
		x_step *= -1;
	if (ray->facing_up)
		y_intercect--;
	while (!is_wall(x_intercect, y_intercect, game))
	{
		x_intercect += x_step;
		y_intercect += y_step;
	}
	ray->wall_hit_x = x_intercect;
	ray->wall_hit_y = y_intercect;
}
