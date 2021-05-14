/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:11:50 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/28 13:23:02 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_and_exit_stg(t_scene *stg, char *err_msg)
{
	free_stg(stg);
	printf("%s\n", err_msg);
	exit(SUCCESS);
}

void	free_sprites(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->sprs_num)
		free(game->sprs[i]);
	if (game->sprs)
		free(game->sprs);
}

void	exit_game(t_game *game, char *err_msg)
{
	free_stg(&game->stg);
	free_sprites(game);
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
		game->player.walk_dir = UP;
	else if (keycode == 100 || keycode == D)
		game->player.walk_dir = RIGHT;
	else if (keycode == 115 || keycode == S)
		game->player.walk_dir = DOWN;
	else if (keycode == 97 || keycode == A)
		game->player.walk_dir = LEFT;
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
		game->player.walk_dir = 0;
	else if (keycode == 65363 || keycode == 65361 || keycode == ARR_LEFT || keycode == ARR_RIGHT)
		game->player.turn_dir = 0;
	return (1);
}
