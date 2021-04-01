/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:21:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/01 23:21:32 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		normalize_angle(double ray_ang)
{
	ray_ang =  fmod(ray_ang, 2 * M_PI);
	if (ray_ang < 0)
		ray_ang += (2 * M_PI);
	return (ray_ang);
}

double	get_horizontal_distance(t_game *game, t_ray *ray)
{
	double x_intercept;
	double y_intercept;
	double x_step;
	double y_step;

	y_intercept = floor(ray->ray.x / game->settings.tile_size.y) * game->settings.tile_size.y;
	x_intercept = ray->ray.x + (y_intercept - ray->ray.y) / tan(ray->ray.direction);
	if (!ray->facing_up)
		y_intercept += game->settings.tile_size.y;
	y_step = game->settings.tile_size.y;
	x_step = y_step / tan(ray->ray.direction);
	if (ray->facing_up)
		y_step *= -1;
	printf("y_step: %f x_step value: %f angle value : %f\n", y_step, x_step, ray->ray.direction);
	if (!ray->facing_right && x_step > 0)
		x_step *= -1;
	if (ray->facing_right && x_step < 0)
		x_step *= -1;
	return (0);
}

double	get_distance_from_wall(t_game *game, t_ray *ray)
{
	double h;
	//double v;

	h = get_horizontal_distance(game, ray);
	v = get_vertical_distance(game, ray);

	if (h < v)
		return (h);
	return (v);
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
	ray->ray.size = game->player.line.size;
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
	ray->distance = get_distance_from_wall(game, ray);
	return (ray);
}


void	render_rays(t_game *game)
{
	double	ray_ang;
	int		i;

	i = 0;
	ray_ang = game->player.rotation_angle - (game->player.fov_ang / 2);
	while (i < game->player.num_rays)
	{
		game->player.rays[i] = create_ray(game, ray_ang);
		draw_line(&game->img, game->player.rays[i]->ray);
		i++;
		ray_ang += game->player.fov_ang / game->player.num_rays;
	}
}
