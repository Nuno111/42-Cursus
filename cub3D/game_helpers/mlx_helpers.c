/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:11:50 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/21 22:33:54 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_and_exit_settings(t_scene *settings, char *err_msg)
{
	free_settings(settings);
	printf("%s\n", err_msg);
	exit(ERR);
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
	printf("%d\n", keycode);
	if (keycode == 65307 || keycode == 53)
		exit_game(game, NULL);
	if (keycode == 119 || keycode == 13)
		game->player.walk_dir = 1;
	else if (keycode == 100 || keycode == 2)
	{
		game->player.walk_dir = 1;
		game->player.strafe = true;
	}
	else if (keycode == 115 || keycode == 1)
		game->player.walk_dir = -1;
	else if (keycode == 97 || keycode == 0)
	{
		game->player.strafe = true;
		game->player.walk_dir = -1;
	}
	else if (keycode == 65361 || keycode == 123)
		game->player.turn_dir = -1;
	else if (keycode == 65363 || keycode == 124)
		game->player.turn_dir = 1;
	update_game(game);
	return (1);
}

int		key_release(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 100 || keycode == 115 || keycode == 97
		|| keycode == 13 || keycode == 2 || keycode == 1 || keycode == 0)
	{
		game->player.walk_dir = 0;
		game->player.strafe = false;
	}
	else if (keycode == 65363 || keycode == 65361 || keycode == 123 || keycode == 124)
		game->player.turn_dir = 0;
	return (1);
}
