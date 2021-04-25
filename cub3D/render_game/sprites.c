/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:24:29 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/24 22:42:59 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	**realloc_sprs(t_game *game, t_sprite **arr, t_sprite *new)
{
	t_sprite **new_arr;
	int		i;

	i = -1;
	new_arr = malloc(sizeof(t_sprite *) * (game->sprs_num + 1));
	if (!new_arr)
		exit_game(game, "Error\nFailed to allocate memory for sprites array.");
	while (++i < game->sprs_num)
		new_arr[i] = arr[i];
	new_arr[i] = new;
	while (++i < game->sprs_num)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
	return (new_arr);
}

void    update_spr_ang(t_game *game, int i)
{
    double  x;
    double  y;

    x = game->sprs[i]->x - (game->player.circle.x / game->minimap_tile.size) * game->cube_size;
    y = game->sprs[i]->y - (game->player.circle.y / game->minimap_tile.size) * game->cube_size;
    game->sprs[i]->ang = normalize_angle(atan2(x, y) - game->player.rot_ang);
}

void	update_spr_visibility(t_game *game, int i)
{
	if (game->sprs[i]->ang < -M_PI)
		game->sprs[i]->ang += 2.0 * M_PI;
	if(game->sprs[i]->ang > M_PI)
		game->sprs[i]->ang -= 2.0 * M_PI;
	game->sprs[i]->ang = fabs(game->sprs[i]->ang);
	if (game->sprs[i]->ang < game->player.fov_ang / 2)
		printf("Ray %d is visibile\n", i);
}
void	get_spr_distance(t_game *game, int i)
{
	game->sprs[i]->dist = get_distance(game->sprs[i]->x, game->sprs[i]->y,
							game->player.circle.x, game->player.circle.y);
}

void	get_spr_height(t_game *game, int i)
{
	double distance;

	distance = (game->sprs[i]->dist / game->minimap_tile.size) * game->cube_size;
	game->sprs[i]->h = (game->cube_size / distance) * game->player.dtpp;
}

void	get_spr_line_pos(t_game *game, int i)
{
	game->sprs[i]->start = game->settings.height / 2 - game->sprs[i]->h / 2;
	game->sprs[i]->end = game->sprs[i]->start + game->sprs[i]->h;
}
void	draw_sprites(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->sprs_num)
	{
		update_spr_ang(game, i);
		update_spr_visibility(game, i);
		//get_spr_distance(game, i);
		//get_spr_height(game, i);
		//get_spr_line_pos(game, i);
	}
}
