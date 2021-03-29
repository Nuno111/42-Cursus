/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:30:45 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/29 15:20:45 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	get_player_rotation(char c, t_game *game)
{
	if (c == 'N')
		game->player.rotation_angle = M_PI / 2;
	else if (c == 'E')
		game->player.rotation_angle = 0;
	else if (c == 'S')
		game->player.rotation_angle = 2 * M_PI / 3;
	else if (c == 'W')
		game->player.rotation_angle = M_PI;
}

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
			game->player.circle.x = (w * game->settings.tile_size.x) + (game->settings.tile_size.x / 2.0) ;
			game->player.circle.y = h * game->settings.tile_size.y + (game->settings.tile_size.x / 2.0);
			break;
		}
		h++;
	}
	get_player_rotation(game->settings.map[h][w], game);
}

void	init_player(t_game *game)
{
	get_player_pos(game);
	game->player.circle.radius = game->settings.tile_size.x / 4.0;
	game->player.circle.color = 0x7F0000;
	game->player.circle.ang = 0;
	game->player.turn_dir = 0;
	game->player.walk_dir = 0;
	game->player.move_speed = 1;
	game->player.rotation_speed = 2 * (M_PI / 180);
	game->player.line.x = game->player.circle.x;
	game->player.line.y = game->player.circle.y;
	game->player.line.color = 0x008000;
	game->player.line.direction = game->player.rotation_angle;
	game->player.line.size = game->player.circle.radius * 2;
	draw_circle(&game->img, game->player.circle);
	draw_inner_circle(&game->img, game->player.circle);
	draw_line(&game->img, game->player.line);
}
