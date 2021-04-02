/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:38:27 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/02 11:48:32 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall(double x, double y, t_game *game)
{
	int index_w;
	int index_h;
	char	c;

	index_w = x / game->map_tile.size;
	index_h = y / game->map_tile.size;
	c = game->settings.map[index_h][index_w];
	if (c == '1' || c == '2')
		return (true);
	return (false);
}

static	void	update_line(t_game *game)
{
	game->player.line.x = game->player.circle.x;
	game->player.line.y = game->player.circle.y;
	game->player.line.direction = game->player.rotation_angle;
}

static  void    update_player(t_game *game)
{
	double move_step;
	double tmp_x;
	double tmp_y;

	game->player.rotation_angle += game->player.turn_dir * game->player.rotation_speed;
	move_step = game->player.walk_dir * game->player.move_speed;
	if (game->player.strafe)
	{
		tmp_x = game->player.circle.x + sin(game->player.rotation_angle) * -move_step;
		tmp_y = game->player.circle.y + cos(game->player.rotation_angle) * move_step;
	}
	else
	{
		tmp_x = game->player.circle.x + cos(game->player.rotation_angle) * move_step;
		tmp_y = game->player.circle.y + sin(game->player.rotation_angle) * move_step;
	}
	if (!is_wall(tmp_x, tmp_y, game))
	{
		game->player.circle.x = tmp_x;
		game->player.circle.y = tmp_y;
	}
}

void    update_game(t_game *game)
{
	create_minimap(&game->settings, game);
    update_player(game);
	update_line(game);
	draw_circle(&game->img, game->player.circle);
	draw_inner_circle(&game->img, game->player.circle);
	draw_line(&game->img, game->player.line);
	render_rays(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->img.img, 0, 0);
}
