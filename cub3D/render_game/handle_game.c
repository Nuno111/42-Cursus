/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:34:11 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/22 11:56:40 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	draw_game(t_game *game)
{
	draw_floor_ceil(game, *game->settings.floor, true);
	draw_floor_ceil(game, *game->settings.ceil, false);
	draw_walls(game);
	draw_minimap(&game->settings, game);
	draw_circle(&game->main_img, game->player.circle, game->settings.res->width);
	draw_inner_circle(&game->main_img, game->player.circle, game->settings.res->width);
	draw_rays(game);
}

static	int    render_next_frame(t_game *game)
{

	game->main_img.img = mlx_new_image(game->mlx, game->settings.res->width, game->settings.res->height);
	game->main_img.addr = (int *)mlx_get_data_addr(game->main_img.img, &game->main_img.bits_per_pixel, &game->main_img.line_length, &game->main_img.endian);
    update_player(game);
	reset_rays(game);
	update_rays(game);
	draw_game(game);
	mlx_put_image_to_window(game->mlx, game->win, game->main_img.img, 0, 0);
	mlx_destroy_image(game->mlx, game->main_img.img);
	game->main_img.img = NULL;
	game->main_img.addr = NULL;
	return (1);
}

void    render_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->settings.res->width, game->settings.res->height, "CUB3D");
	game->cube_size = 64;
	game->minimap_tile.size = (game->settings.res->width / game->settings.map_width) / 3;
	mlx_do_key_autorepeatoff(game->mlx);
	init_player(game);
	init_walls(game);
	create_rays(game);
	mlx_hook(game->win, 2, 1L<<0, key_press, game);
	mlx_hook(game->win, 3, 1L<<1, key_release, game);
	mlx_hook(game->win, 17,1L<<17, handle_destroy, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
}
