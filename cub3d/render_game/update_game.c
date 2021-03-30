/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:38:27 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/30 22:03:40 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	update_line(t_game *game)
{
	game->player.line.x = game->player.circle.x;
	game->player.line.y = game->player.circle.y;
	game->player.line.direction = game->player.rotation_angle;
}

static  void    update_player(t_game *game)
{
	double move_step;

	game->player.rotation_angle += game->player.turn_dir * game->player.rotation_speed;
	move_step = game->player.walk_dir * game->player.move_speed;
	if (game->player.strafe_dir)
	{
		printf("strafing");
		game->player.circle.y += cos(game->player.rotation_angle) * move_step;
		game->player.circle.x += sin(game->player.rotation_angle) * -move_step;
	}
	else
	{
		game->player.circle.x += cos(game->player.rotation_angle) * move_step;
		game->player.circle.y += sin(game->player.rotation_angle) * move_step;
	}
	printf("%f", move_step);
}

void    update_game(t_game *game)
{
	create_minimap(&game->settings, game);
    update_player(game);
	update_line(game);
	draw_circle(&game->img, game->player.circle);
	draw_inner_circle(&game->img, game->player.circle);
	draw_line(&game->img, game->player.line);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->img.img, 0, 0);
}
