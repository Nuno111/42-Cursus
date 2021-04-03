/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:21:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/03 00:26:40 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray*   create_ray(t_game *game, double ray_ang)
{
	t_ray *ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		error_and_exit_game(game, "Error\nUnable to allocate memory for ray.");
	ray->ray.x = game->player.circle.x;
	ray->ray.y = game->player.circle.y;
	ray->ray.direction = normalize_angle(ray_ang);
	ray->ray.color = game->player.circle.color;
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
