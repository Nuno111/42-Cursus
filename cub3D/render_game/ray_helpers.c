/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:39:24 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/22 12:11:26 by ngregori         ###   ########.fr       */
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
	while (intercect.x < game->settings.width && intercect.y < game->settings.height &&
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
	intercect.y = floor(ray->line.y / game->minimap_tile.size) * game->minimap_tile.size;
	if (!ray->facing_up)
		intercect.y += game->minimap_tile.size;
	intercect.x = ray->line.x + (intercect.y - ray->line.y) / tan(ray->line.direction);
	intercect.y_step = game->minimap_tile.size;
	if (ray->facing_up)
		intercect.y_step *= -1;
	intercect.x_step = game->minimap_tile.size / tan(ray->line.direction);
	if (!ray->facing_right && intercect.x_step > 0)
		intercect.x_step *= -1;
	if (ray->facing_right && intercect.x_step < 0)
		intercect.x_step *= -1;
	if (ray->facing_up)
		intercect.y-= 0.00001;
	else
		intercect.y_offset = 0;
	did_ray_hit_wall(game, ray, intercect, true);
}

void		get_vertical_intercection(t_game *game, t_ray *ray)
{
	t_intercect intercect;

	intercect.y_offset = 0;
	intercect.x = floor(ray->line.x / game->minimap_tile.size) * game->minimap_tile.size;
	if (ray->facing_right)
		intercect.x += game->minimap_tile.size;
	intercect.y = ray->line.y + (intercect.x - ray->line.x) * tan(ray->line.direction);
	intercect.x_step = game->minimap_tile.size;
	if (!ray->facing_right)
		intercect.x_step *= -1;
	intercect.y_step = game->minimap_tile.size * tan(ray->line.direction);
	if (ray->facing_up && intercect.y_step > 0)
		intercect.y_step *= -1;
	if (!ray->facing_up && intercect.y_step < 0)
		intercect.y_step *= -1;
	if (!ray->facing_right)
		intercect.x-= 0.00001;
	did_ray_hit_wall(game, ray, intercect, false);
}
