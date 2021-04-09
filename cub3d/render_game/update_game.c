/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:38:27 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/09 18:43:00 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	update_rays(t_game *game)
{

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
    update_player(game);
	create_rays(game);
	draw_walls(game);
	draw_minimap(&game->settings, game);
	draw_circle(&game->main_img, game->player.circle);
	draw_inner_circle(&game->main_img, game->player.circle);
	draw_rays(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->main_img.img, 0, 0);
}
