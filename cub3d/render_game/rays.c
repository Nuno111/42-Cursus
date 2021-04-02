/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:21:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/02 12:46:34 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		get_distance(t_ray ray)
{
	double distance;

	distance = (ray.wall_hit_x - ray.ray.x) * (ray.wall_hit_x - ray.ray.x) +
				(ray.wall_hit_y - ray.ray.y) * (ray.wall_hit_y - ray.ray.y);
	return sqrt(distance);
}

double		normalize_angle(double ray_ang)
{
	ray_ang =  fmod(ray_ang, 2 * M_PI);
	if (ray_ang < 0)
		ray_ang += (2 * M_PI);
	return (ray_ang);
}

void	find_wall_hit(t_game *game, t_ray *ray, double x, double y, double x_step, double y_step)
{
	double next_x;
	double next_y;

	next_x = x;
	next_y = y;
	if (ray->facing_up)
		next_y--;
	while (!is_wall(next_x, next_y, game))
	{
		next_x += x_step;
		next_y += y_step;
	}
	ray->wall_hit_x = next_x;
	ray->wall_hit_y = next_y;
}

void	get_horizontal_intercection(t_game *game, t_ray *ray)
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
	x_step = y_step / tan(ray->ray.direction);
	if (ray->facing_up)
		y_step *= -1;
	if (!ray->facing_right && x_step > 0)
		x_step *= -1;
	if (ray->facing_right && x_step < 0)
		x_step *= -1;
	find_wall_hit(game, ray, x_intercect, y_intercect, x_step, y_step);
}

t_ray*   create_ray(t_game *game, double ray_ang)
{
	t_ray *ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		error_and_exit_game(game, "Error\nUnable to allocate memory for ray.");
	ray->ray.x = game->player.circle.x;
	ray->ray.y = game->player.circle.y;
	ray->ray.direction = normalize_angle(ray_ang);
	ray->ray.color = game->player.line.color;
	ray->wall_hit_x = 0;
	ray->wall_hit_y = 0;
	if (ray->ray.direction >= M_PI  && ray->ray.direction <= 2 * M_PI)
		ray->facing_up = true;
	else
		ray->facing_up = false;
	if (ray->ray.direction < 0.5 * M_PI  || ray->ray.direction > 1.5 * M_PI)
		ray->facing_right = true;
	else
		ray->facing_right = false;
	get_horizontal_intercection(game, ray);
	ray->ray.size = get_distance(*ray);
	return (ray);
}


void	render_rays(t_game *game)
{
	double	ray_ang;
	int		i;

	i = 0;
	ray_ang = game->player.rotation_angle - (game->player.fov_ang / 2);
	while (i < 1)
	{
		game->player.rays[i] = create_ray(game, ray_ang);
		draw_line(&game->img, game->player.rays[i]->ray);
		i++;
		ray_ang += game->player.fov_ang / game->player.num_rays;
	}
}
