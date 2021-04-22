/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:11:50 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/22 01:34:02 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_and_exit_settings(t_scene *settings, char *err_msg)
{
	free_settings(settings);
	printf("%s\n", err_msg);
	exit(SUCCESS);
}

void	exit_game(t_game *game, char *err_msg)
{
	free_settings(&game->settings);
	if (err_msg)
	{
		printf("%s\n", err_msg);
		exit(ERR);
	}
	exit(SUCCESS);
}

int		handle_destroy(t_game *game)
{
	exit_game(game, NULL);
	return (1);
}

int		key_press(int keycode, t_game *game)
{
	if (keycode == 65307 || keycode == ESC)
		exit_game(game, NULL);
	if (keycode == 119 || keycode == W)
		game->player.walk_dir = 1;
	else if (keycode == 100 || keycode == D)
	{
		game->player.walk_dir = 1;
		game->player.strafe = true;
	}
	else if (keycode == 115 || keycode == S)
		game->player.walk_dir = -1;
	else if (keycode == 97 || keycode == A)
	{
		game->player.strafe = true;
		game->player.walk_dir = -1;
	}
	else if (keycode == 65361 || keycode == ARR_LEFT)
		game->player.turn_dir = -1;
	else if (keycode == 65363 || keycode == ARR_RIGHT)
		game->player.turn_dir = 1;
	return (1);
}

int		key_release(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 100 || keycode == 115 || keycode == 97
		|| keycode == W || keycode == D || keycode == S || keycode == A)
	{
		game->player.walk_dir = 0;
		game->player.strafe = false;
	}
	else if (keycode == 65363 || keycode == 65361 || keycode == ARR_LEFT || keycode == ARR_RIGHT)
		game->player.turn_dir = 0;
	return (1);
}
