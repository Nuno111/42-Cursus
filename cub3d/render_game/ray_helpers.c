/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:39:24 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/03 15:14:04 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		get_distance(double x, double y, double hit_x, double hit_y)
{
	double distance;

	distance = (hit_x - x) * (hit_x - x) + (hit_y - y) * (hit_y - y);
	return (sqrt(distance));
}

double		normalize_angle(double ray_ang)
{
	ray_ang = fmod(ray_ang, 2 * M_PI);
	if (ray_ang < 0)
		ray_ang += (2 * M_PI);
	return (ray_ang);
}

void		did_ray_hit_wall(t_game *game, t_ray *ray, t_intercect intercect, bool hrzt)
{
	while (intercect.x < game->settings.res->x && intercect.y < game->settings.res->y &&
			intercect.x > 0 && intercect.y > 0)
	{
		if (is_wall(intercect.x, intercect.y, game))
		{
			if (hrzt)
			{
				ray->hrzt_hit = true;
				ray->hrzt_hit_x = intercect.x;
				ray->hrzt_hit_y = intercect.y;
			}
			else
			{
				ray->vrtc_hit = true;
				ray->vrtc_hit_x = intercect.x;
				ray->vrtc_hit_y = intercect.y;
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

void		get_horizontal_intercection(t_game *game, t_ray *ray)
{
	t_intercect intercect;

	intercect.x_offset = 0;
	intercect.y = floor(ray->ray.y / game->settings.tile_size.y) * game->settings.tile_size.y;
	if (!ray->facing_up)
		intercect.y += game->settings.tile_size.y;
	intercect.x = ray->ray.x + (intercect.y - ray->ray.y) / tan(ray->ray.direction);
	intercect.y_step = game->settings.tile_size.y;
	if (ray->facing_up)
		intercect.y_step *= -1;
	intercect.x_step = game->settings.tile_size.x / tan(ray->ray.direction);
	if (!ray->facing_right && intercect.x_step > 0)
		intercect.x_step *= -1;
	if (ray->facing_right && intercect.x_step < 0)
		intercect.x_step *= -1;
	if (ray->facing_up)
		intercect.y--;
	else
		intercect.y_offset = 0;
	did_ray_hit_wall(game, ray, intercect, true);
}

void		get_vertical_intercection(t_game *game, t_ray *ray)
{
	t_intercect intercect;

	intercect.y_offset = 0;
	intercect.x = floor(ray->ray.x / game->settings.tile_size.x) * game->settings.tile_size.x;
	if (ray->facing_right)
		intercect.x += game->settings.tile_size.x;
	intercect.y = ray->ray.y + (intercect.x - ray->ray.x) * tan(ray->ray.direction);
	intercect.x_step = game->settings.tile_size.x;
	if (!ray->facing_right)
		intercect.x_step *= -1;
	intercect.y_step = game->settings.tile_size.y * tan(ray->ray.direction);
	if (ray->facing_up && intercect.y_step > 0)
		intercect.y_step *= -1;
	if (!ray->facing_up && intercect.y_step < 0)
		intercect.y_step *= -1;
	if (!ray->facing_right)
		intercect.x--;
	did_ray_hit_wall(game, ray, intercect, false);
}
