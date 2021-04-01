/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:21:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/01 16:11:19 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		normalize_angle(double ray_ang)
{

	ray_ang =  fmod(ray_ang, 2 * M_PI);
	if (ray_ang < 0)
		ray_ang += (2 * M_PI);
}


t_line*   create_ray(t_game *game, double ray_ang)
{
	t_line *ray;

	ray = malloc(sizeof(t_line));
	if (!ray)
		error_and_exit_game(game, "Error\nUnable to allocate memory for ray.");
	ray->x = game->player.circle.x;
	ray->y = game->player.circle.y;
	ray->direction = ray_ang;
	ray->size = game->player.line.size;
	ray->color = game->player.line.color;
	return (ray);
}

void	cast_rays(t_game *game)
{
	double	ray_ang;
	int		i;

	i = 0;
	ray_ang = game->player.rotation_angle - (game->player.fov_ang / 2);
	while (i < game->player.num_rays)
	{
		game->player.rays[i] = create_ray(game, ray_ang);
		draw_line(&game->img, *game->player.rays[i]);
		i++;
		ray_ang += game->player.fov_ang / game->player.num_rays;
	}
}
