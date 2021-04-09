/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:34:11 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/09 11:26:10 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    render_game(t_game *game)
{
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, game->settings.res->x, game->settings.res->y, "CUB3D");
	game->main_img.img = mlx_new_image(game->vars.mlx, game->settings.res->x, game->settings.res->y);
	game->main_img.addr = mlx_get_data_addr(game->main_img.img, &game->main_img.bits_per_pixel, &game->main_img.line_length, &game->main_img.endian);
	game->cube_size = 64;
	create_minimap(&game->settings, game);
	init_player(game);
	game->dtpp = (game->settings.res->x / 2) / tan(game->player.fov_ang / 2);
	render_rays(game);
	render_walls(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->main_img.img, 0, 0);
	mlx_hook(game->vars.win, 2, 1L<<0, key_press, game);
	mlx_hook(game->vars.win, 3, 1L<<1, key_release, game);
	mlx_loop(game->vars.mlx);
}
