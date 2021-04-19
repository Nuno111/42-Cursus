/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:34:11 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/18 10:33:14 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	draw_test(t_game *game)
{
	int y = 0;
	t_color color;
	int posy = game->settings.res->y / 2;
	while (y < 64)
	{
		int x = 0;
		int posx = game->settings.res->x / 2;
		while (x < 64 * 4)
		{
			color.t = game->walls.no.addr[x + 3 + y * game->walls.no.line_length];
			color.r = game->walls.no.addr[x + 2 + y * game->walls.no.line_length];
			color.g = game->walls.no.addr[x + 1 + y * game->walls.no.line_length];
			color.b = game->walls.no.addr[x + y * game->walls.no.line_length];
			color.trgb = create_trgb(color.t, color.r, color.b, color.b);
			my_mlx_pixel_put(&game->main_img, posx, posy, color.trgb);
			x+=4;
			posx++;
		}
		y++;
		posy++;
	}
}
void    update_game(t_game *game)
{
	mlx_destroy_image(game->vars.mlx, game->main_img.img);
	game->main_img.img = mlx_new_image(game->vars.mlx, game->settings.res->x, game->settings.res->y);
	game->main_img.addr = mlx_get_data_addr(game->main_img.img, &game->main_img.bits_per_pixel, &game->main_img.line_length, &game->main_img.endian);
    update_player(game);
	reset_rays(game);
	update_rays(game);
	draw_walls(game);
	draw_minimap(&game->settings, game);
	draw_circle(&game->main_img, game->player.circle);
	draw_inner_circle(&game->main_img, game->player.circle);
	draw_rays(game);
	draw_test(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->main_img.img, 0, 0);
}

void    render_game(t_game *game)
{
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, game->settings.res->x, game->settings.res->y, "CUB3D");
	game->main_img.img = mlx_new_image(game->vars.mlx, game->settings.res->x, game->settings.res->y);
	game->main_img.addr = mlx_get_data_addr(game->main_img.img, &game->main_img.bits_per_pixel, &game->main_img.line_length, &game->main_img.endian);
	game->cube_size = 64;
	game->minimap_tile.size = (game->settings.res->x / game->settings.map_width) / 3;
	init_player(game);
	init_walls(game);
	create_rays(game);
	draw_walls(game);
	draw_minimap(&game->settings, game);
	draw_circle(&game->main_img, game->player.circle);
	draw_inner_circle(&game->main_img, game->player.circle);
	draw_rays(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->main_img.img, 0, 0);
	mlx_hook(game->vars.win, 2, 1L<<0, key_press, game);
	mlx_hook(game->vars.win, 3, 1L<<1, key_release, game);
	mlx_loop(game->vars.mlx);
}
