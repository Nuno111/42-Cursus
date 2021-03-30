/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:11:50 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/30 22:05:28 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		mlx_destroy_window(game->vars.mlx, game->vars.win);
	if (keycode == 119)
		game->player.walk_dir = 1;
	else if (keycode == 100)
	{
		game->player.walk_dir = 1;
		game->player.strafe_dir = 1;
	}
	else if (keycode == 115)
		game->player.walk_dir = -1;
	else if (keycode == 97)
	{
		game->player.strafe_dir = 1;
		game->player.walk_dir = -1;
	}
	else if (keycode == 65361)
		game->player.turn_dir = -1;
	else if (keycode == 65363)
		game->player.turn_dir = 1;
	update_game(game);
	return (1);
}

int		key_release(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 100 || keycode == 115 || keycode == 97)
	{
		game->player.walk_dir = 0;
		game->player.strafe_dir = 0;
	}
	else if (keycode == 65363 || keycode == 65361)
		game->player.turn_dir = 0;
	return (1);
}
