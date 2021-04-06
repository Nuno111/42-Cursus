/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:34:11 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/05 21:15:20 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    render_game(t_game *game)
{
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, game->settings.res->x, game->settings.res->y, "CUB3D");
	game->img.img = mlx_new_image(game->vars.mlx, game->settings.res->x, game->settings.res->y);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	game->settings.tile_size.x = (game->settings.res->x / game->settings.map_width) / 2;
	game->settings.tile_size.y = game->settings.tile_size.x;
	create_minimap(&game->settings, game);
	init_player(game);
	render_rays(game);
	render_walls(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->img.img, 0, 0);
	mlx_hook(game->vars.win, 2, 1L<<0, key_press, game);
	mlx_hook(game->vars.win, 3, 1L<<1, key_release, game);
	mlx_loop(game->vars.mlx);
}
