/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:24:29 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/24 14:50:38 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    is_spr_visible(t_game *game, int i)
{
    double  x;
    double  y;
    double  ang_to_spr;
    double  ang_diff;

    x = game->sprs[i]->x - game->player.circle.x;
    y = game->sprs[i]->y - game->player.circle.y;
    ang_to_spr = normalize_ang(atan2(x, y));
	ang_diff = normalize_ang(game->player.circle.ang - ang_to_spr);

	if (ang_diff < game->player.fov_ang / 2)
		game->sprs[i]->visible = true;
	else
		game->sprs[i]->visible = false;
	//move somewhere else
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

	i = 0;
	while (i < game->sprs_num)
	{
		is_spr_visible(game, i);
		get_spr_distance(game, i);
		get_spr_height(game, i);
		get_spr_line_pos(game, i);

	}
}
