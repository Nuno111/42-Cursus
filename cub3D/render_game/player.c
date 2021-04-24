/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:30:45 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/24 15:07:11 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	get_player_rotation(char c, t_game *game)
{
	if (c == 'N')
		game->player.rot_ang = -(M_PI / 2);
	else if (c == 'E')
		game->player.rot_ang = 0;
	else if (c == 'S')
		game->player.rot_ang = M_PI / 2;
	else if (c == 'W')
		game->player.rot_ang = M_PI;
}

void	get_player_pos(t_game *game)
{
	int h;
	int w;

	h = 0;
	while (game->settings.map[h])
	{
		w = 0;
		while (game->settings.map[h][w])
		{
			if (ft_strchr("NESW", game->settings.map[h][w]))
			{
				game->player.circle.x = (w * game->minimap_tile.size) + (game->minimap_tile.size / 2.0);
				game->player.circle.y = (h * game->minimap_tile.size) + (game->minimap_tile.size/ 2.0);
				get_player_rotation(game->settings.map[h][w], game);
				return;
			}
			w++;
		}
		h++;
	}
}

void    update_player(t_game *game)
{
	double move_step;
	double tmp_x;
	double tmp_y;

	if (game->player.turn_dir != 0)
		game->player.rot_ang += game->player.turn_dir * game->player.rot_speed;
	if (game->player.walk_dir != 0)
	{
		move_step = game->player.walk_dir * game->player.move_speed;
		tmp_x = game->player.circle.x + cos(game->player.rot_ang) * move_step;
		tmp_y = game->player.circle.y + sin(game->player.rot_ang) * move_step;
		if (game->player.strafe)
		{
			tmp_x = game->player.circle.x + sin(game->player.rot_ang) * -move_step;
			tmp_y = game->player.circle.y + cos(game->player.rot_ang) * move_step;
		}
		if (!is_wall(tmp_x, tmp_y, game) && !is_sprite(tmp_x, tmp_y, game))
		{
			game->player.circle.x = tmp_x;
			game->player.circle.y = tmp_y;
		}
	}
}

