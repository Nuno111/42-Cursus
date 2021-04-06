/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:11:50 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/31 16:05:13 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int		key_press(int keycode, t_game *game)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
		mlx_destroy_window(game->vars.mlx, game->vars.win);
	if (keycode == 119 || keycode == 13)
		game->player.walk_dir = 1;
	else if (keycode == 100 || keycode == 2)
	{
		game->player.walk_dir = 1;
		game->player.strafe = true;
	}
	else if (keycode == 115 || keycode == 1)
		game->player.walk_dir = -1;
	else if (keycode == 97 || 0)
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
