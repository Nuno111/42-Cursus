/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:30:45 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/29 14:48:45 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	get_player_pos(t_game *game)
{
	int h;
	int w;

	h = 0;
	while (game->settings.map[h][w])
	{
		w = 0;
		while (!ft_strchr("NESW", game->settings.map[h][w]))
			w++;
		if (ft_strchr("NESW", game->settings.map[h][w]))
		{
			game->player.circle.x = w * game->settings.tile_size.x;
			game->player.circle.y = h * game->settings.tile_size.y;
			break;
		}
		h++;
	}
}

void	init_player(t_game *game, t_scene *settings, int x, int y)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	if (!player)
		error_and_exit(settings, "Error\nUnable to allocate memory for player");
	player->circle.x = x + settings->tile_size.x / 2.0;
	player->circle.y = y + settings->tile_size.x / 2.0;
	player->circle.radius = settings->tile_size.x / 4.0;
	player->circle.color = 0x7F0000;
	player->circle.ang = 0;
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->rotation_angle = 0;
	player->move_speed = 1;
	player->rotation_speed = 2 * (M_PI / 180);
	player->line.x = player->circle.x;
	player->line.y = player->circle.y;
	player->line.color = 0x008000;
	player->line.direction = player->rotation_angle;
	player->line.size = player->circle.radius * 2;
	draw_circle(&game->img, player->circle);
	draw_inner_circle(&game->img, player->circle);
	draw_line(&game->img, player->line);
	game->player = player;
}
