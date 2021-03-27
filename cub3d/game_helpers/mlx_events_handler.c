/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:11:50 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/27 19:54:02 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		mlx_destroy_window(game->vars.mlx, game->vars.win);
	else if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100 || keycode == 65361 || keycode == 65363)
		printf("%d\n", keycode);
	else
		return (1);
	return (0);
}

int		key_release(int keycode, t_game *game)
{
	if (keycode == 65307)
		mlx_destroy_window(game->vars.mlx, game->vars.win);
	else if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100 || keycode == 65361 || keycode == 65363)
		printf("%d\n", keycode);
	else
		return (1);
	return (0);
}
