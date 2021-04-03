/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:30:45 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/03 18:25:05 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	get_player_rotation(char c, t_game *game)
{
	if (c == 'N')
		game->player.rotation_angle = -(M_PI / 2);
	else if (c == 'E')
		game->player.rotation_angle = 0;
	else if (c == 'S')
		game->player.rotation_angle = M_PI / 1.3;
	else if (c == 'W')
		game->player.rotation_angle = M_PI;
}

static	void	get_player_pos(t_game *game)
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
				game->player.circle.x = (w * game->settings.tile_size.x) + (game->settings.tile_size.x / 2.0);
				game->player.circle.y = (h * game->settings.tile_size.y) + (game->settings.tile_size.x / 2.0);
				get_player_rotation(game->settings.map[h][w], game);
				return;
			}
			w++;
		}
		h++;
	}
}

void	init_player(t_game *game)
{
	get_player_pos(game);
	game->player.circle.radius = game->settings.tile_size.x / 4.0;
	game->player.circle.color = 0x7F0000;
	game->player.circle.ang = 0;
	game->player.turn_dir = 0;
	game->player.walk_dir = 0;
	game->player.move_speed = 3;
	game->player.rotation_speed = (M_PI / 20);
	game->player.line.x = game->player.circle.x;
	game->player.line.y = game->player.circle.y;
	game->player.line.color = 0x008000;
	game->player.line.direction = game->player.rotation_angle;
	game->player.line.size = game->player.circle.radius * 4;
	game->player.strafe = false;
	game->player.fov_ang = deg_to_rad(60);
	game->player.wall_wid = 1;
	game->player.num_rays = game->settings.res->x / game->player.wall_wid;
	game->player.rays = malloc(sizeof (t_line *) * game->player.num_rays);
	if (!game->player.rays)
		error_and_exit_game(game, "Error\nUnable to allocate memory for rays");
	draw_circle(&game->img, game->player.circle);
	draw_inner_circle(&game->img, game->player.circle);
}
