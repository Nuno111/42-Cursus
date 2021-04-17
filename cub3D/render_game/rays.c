/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:21:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/17 15:26:52 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reset_rays(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->player.num_rays)
	{
		game->player.rays[i]->distance = 0;
		game->player.rays[i]->facing_right = false;
		game->player.rays[i]->facing_up = false;
		game->player.rays[i]->hrzt_hit = false;
		game->player.rays[i]->hrzt_hit_x = 0;
		game->player.rays[i]->hrzt_hit_y = 0;
		game->player.rays[i]->line.direction = 0;
		game->player.rays[i]->line.size = 0;
		game->player.rays[i]->line.x = 0;
		game->player.rays[i]->line.y = 0;
		game->player.rays[i]->vrtc_hit = false;
		game->player.rays[i]->vrtc_hit_x = 0;
		game->player.rays[i]->vrtc_hit_y = 0;
	}
}

void	cast_ray(t_game *game, t_ray *ray)
{
	double hrzt_dist;
	double vrtc_dist;

	get_horizontal_intercection(game, ray);
	get_vertical_intercection(game, ray);
	if (ray->hrzt_hit)
		hrzt_dist = get_distance(ray->line.x, ray->line.y, ray->hrzt_hit_x, ray->hrzt_hit_y);
	else
		hrzt_dist = DBL_MAX;
	if (ray->vrtc_hit)
		vrtc_dist = get_distance(ray->line.x, ray->line.y, ray->vrtc_hit_x, ray->vrtc_hit_y);
	else
		vrtc_dist = DBL_MAX;
	if (hrzt_dist < vrtc_dist)
	{
		ray->vrtc_hit = false;
		ray->line.size = hrzt_dist;
		ray->texture_pixel = fmod(ray->hrzt_hit_x,game->cube_size);
	}
	else
	{
		ray->hrzt_hit = false;
		ray->line.size = vrtc_dist;
		ray->texture_pixel = fmod(ray->hrzt_hit_y,game->cube_size);
	}
}

t_ray*   create_ray(t_game *game, double ray_ang)
{
	t_ray *ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		error_and_exit_game(game, "Error\nUnable to allocate memory for ray.");
	ray->line.x = game->player.circle.x;
	ray->line.y = game->player.circle.y;
	ray->line.direction = normalize_angle(ray_ang);
	ray->line.color = game->player.circle.color;
	if (ray->line.direction > M_PI  && ray->line.direction < 2 * M_PI)
		ray->facing_up = true;
	else
		ray->facing_up = false;
	if (ray->line.direction < 0.5 * M_PI  || ray->line.direction > 1.5 * M_PI)
		ray->facing_right = true;
	else
		ray->facing_right = false;
	return (ray);
}

void	update_rays(t_game *game)
{
	int	i;
	double ray_ang;

	i = -1;
	ray_ang = game->player.rotation_angle - (game->player.fov_ang / 2);
	while (++i < game->player.num_rays)
	{
		game->player.rays[i]->line.x = game->player.circle.x;
		game->player.rays[i]->line.y = game->player.circle.y;
		game->player.rays[i]->line.direction = normalize_angle(ray_ang);
		if (game->player.rays[i]->line.direction > M_PI  && game->player.rays[i]->line.direction < 2 * M_PI)
			game->player.rays[i]->facing_up = true;
		else
			game->player.rays[i]->facing_up = false;
		if (game->player.rays[i]->line.direction < 0.5 * M_PI  || game->player.rays[i]->line.direction > 1.5 * M_PI)
			game->player.rays[i]->facing_right = true;
		else
			game->player.rays[i]->facing_right = false;
		cast_ray(game, game->player.rays[i]);
		ray_ang += game->player.ang_increment;
	}
}

void	create_rays(t_game *game)
{
	double	ray_ang;
	int		i;

	i = -1;
	ray_ang = game->player.rotation_angle - (game->player.fov_ang / 2);
	while (++i < game->player.num_rays)
	{
		game->player.rays[i] = create_ray(game, ray_ang);
		cast_ray(game, game->player.rays[i]);
		ray_ang += game->player.ang_increment;
	}
}
