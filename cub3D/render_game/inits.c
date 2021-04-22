/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:49:50 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/22 13:46:04 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_settings(t_scene *settings)
{
	settings->height = 0;
	settings->width = 0;
	settings->no = NULL;
	settings->so = NULL;
	settings->we = NULL;
	settings->ea = NULL;
	settings->sprite = NULL;
	settings->floor = NULL;
	settings->ceil = NULL;
	settings->tmp_map = NULL;
	settings->map = NULL;
	settings->map_width = 0;
	settings->map_size = 0;
	settings->line = NULL;
}

static	void	init_player(t_game *game)
{
	get_player_pos(game);
	game->player.circle.radius = game->minimap_tile.size / 4.0;
	game->player.circle.color = 0x7F0000;
	game->player.circle.ang = 0;
	game->player.turn_dir = 0;
	game->player.walk_dir = 0;
	game->player.move_speed = 1;
	game->player.rot_speed = deg_to_rad(3);
	game->player.strafe = false;
	game->player.fov_ang = deg_to_rad(60);
	game->player.num_rays = 1;//game->settings.width;
	game->player.rays = malloc(sizeof (t_ray *) * game->player.num_rays);
	game->player.dtpp = (game->settings.width / 2) / tan(game->player.fov_ang / 2);
	game->player.ang_inc = game->player.fov_ang / game->player.num_rays;
	if (!game->player.rays)
		exit_game(game, "Error\nUnable to allocate memory for rays");
}
static	void	init_txts(t_game *game)
{
	game->txts.no.img = mlx_xpm_file_to_image(game->mlx, game->settings.no, &game->txts.no.width, &game->txts.no.height);
	game->txts.ea.img = mlx_xpm_file_to_image(game->mlx, game->settings.ea, &game->txts.ea.width, &game->txts.ea.height);
	game->txts.so.img = mlx_xpm_file_to_image(game->mlx, game->settings.so, &game->txts.so.width, &game->txts.so.height);
	game->txts.we.img = mlx_xpm_file_to_image(game->mlx, game->settings.we, &game->txts.we.width, &game->txts.we.height);
	game->txts.no.addr = (int *)mlx_get_data_addr(game->txts.no.img, &game->txts.no.bits_per_pixel, &game->txts.no.line_length, &game->txts.no.endian);
	game->txts.ea.addr = (int *)mlx_get_data_addr(game->txts.ea.img, &game->txts.ea.bits_per_pixel, &game->txts.ea.line_length, &game->txts.ea.endian);
	game->txts.so.addr = (int *)mlx_get_data_addr(game->txts.so.img, &game->txts.so.bits_per_pixel, &game->txts.so.line_length, &game->txts.so.endian);
	game->txts.we.addr = (int *)mlx_get_data_addr(game->txts.we.img, &game->txts.we.bits_per_pixel, &game->txts.we.line_length, &game->txts.we.endian);
}

void	init_wall_vars(t_ray *ray)
{
	ray->w_hrzt_hit = false;
	ray->w_hrzt_x = 0;
	ray->w_hrzt_y = 0;
	ray->w_vrtc_hit = false;
	ray->w_hrzt_x = 0;
	ray->w_hrzt_y = 0;
	ray->w_txt_pixel = 0;
}

void	init_sprite_vars(t_ray *ray)
{
	ray->s_hrzt_hit = false;
	ray->s_hrzt_x = 0;
	ray->s_hrzt_y = 0;
	ray->s_vrtc_hit = false;
	ray->s_hrzt_x = 0;
	ray->s_hrzt_y = 0;
	ray->s_txt_pixel = 0;
}
void    init_stuff(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->settings.width, game->settings.height, "CUB3D");
	game->cube_size = 64;
	game->minimap_tile.size = (game->settings.width / game->settings.map_width) / 3;
	init_player(game);
	init_txts(game);
	create_rays(game);

}