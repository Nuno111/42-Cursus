/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:24:29 by ngregori          #+#    #+#             */
/*   Updated: 2021/05/14 16:58:49 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	**realloc_sprs(t_game *game, t_sprite **arr, t_sprite *new)
{
	t_sprite **new_arr;
	int		i;

	i = -1;
	new_arr = malloc(sizeof(t_sprite *) * (game->sprs_num + 1));
	if (!new_arr)
		exit_game(game, "Error\nFailed to allocate memory for sprites array.");
	while (++i < game->sprs_num)
		new_arr[i] = arr[i];
	new_arr[i] = new;
	while (++i < game->sprs_num)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
	return (new_arr);
}

double    get_spr_angle(t_game *game, double spr_x, double spr_y)
{
    double  x;
    double  y;
	double	player_x;
	double	player_y;
	double	ang;

	player_x = (game->player.circle.x / game->minimap_tile.size) * game->cube_size;
	player_y = (game->player.circle.y / game->minimap_tile.size) * game->cube_size;
    x = spr_x - player_x;
    y = spr_y - player_y;
	ang = normalize_angle(atan2(y, x) - game->player.rot_ang);
	return (ang);
}

bool	is_spr_visible(t_game *game, double ang)
{
	if (ang < -M_PI)
		ang += 2.0 * M_PI;
	if (ang > M_PI)
		ang -= 2.0 * M_PI;
	ang = fabs(ang);
	return (ang < game->player.fov_ang / 2);
}

double	get_spr_distance(t_game *game, double spr_x, double spr_y)
{
	double player_x;
	double player_y;

	player_x = (game->player.circle.x / game->minimap_tile.size) * game->cube_size;
	player_y = (game->player.circle.y / game->minimap_tile.size) * game->cube_size;
	return (get_distance(spr_x, spr_y, player_x, player_y));
}

void	get_spr_pos(t_game *game, int i)
{
	double	x_centre;
	double	y_centre;
	double	x_spr_centre;
	double	y_spr_centre;

	x_centre = game->settings.w / 2;
	x_spr_centre = tan(game->sprs[i]->ang) * game->player.dtpp;
	y_centre = game->settings.h / 2;
	y_spr_centre = game->sprs[i]->h / 2;
	game->sprs[i]->x_strt = x_centre + x_spr_centre - (game->sprs[i]->h / 2);
	game->sprs[i]->y_strt = y_centre - y_spr_centre;
	if (game->sprs[i]->y_strt < 0)
		game->sprs[i]->y_strt = 0;
}

void	sort_sprs(t_game *game)
{
	int i;
	bool sorted;
	t_sprite *tmp;

	sorted = false;
	while (!sorted)
	{
		i = -1;
		sorted = true;
		while (++i < game->sprs_num - 1)
		{
			if (game->sprs[i]->dist < game->sprs[i + 1]->dist)
			{
				tmp = game->sprs[i];
				game->sprs[i] = game->sprs[i + 1];
				game->sprs[i + 1] = tmp;
				sorted = false;
			}
		}
	}
}

void	update_sprs(t_game *game)
{
	int i;
	t_sprite *spr;

	i = -1;
	while (++i < game->sprs_num)
	{
		spr = game->sprs[i];
		spr->dist = get_spr_distance(game, spr->x, spr->y);
		spr->ang = get_spr_angle(game, spr->x, spr->y);
		spr->visible = is_spr_visible(game, spr->ang);
		spr->h = (game->cube_size / spr->dist) * game->player.dtpp;
		get_spr_pos(game, i);
	}
	sort_sprs(game);
}

void	draw_sprt_strip(t_game *game, t_sprite *spr, int x_tex, int x_pox)
{
	int		y;
	int		y_tex;
	double	step;
	double	tex_pox;
	int		color;

	step = spr->txt.height / spr->h;
	tex_pox = (spr->y_strt - game->settings.h / 2 + spr->h / 2) * step;
	y = -1;
	while (++y < spr->h && y < game->settings.h)
	{
		y_tex = (int)tex_pox & (spr->txt.height - 1);
		tex_pox += step;
		color = spr->txt.addr[x_tex + y_tex * spr->txt.height];
		if (color < 0)
			continue ;
		game->img.addr[x_pox + (spr->y_strt + y) * game->settings.w] = color;
	}
}

void	draw_sprt(t_game *game, t_sprite *spr)
{
	double	width;
	int		i;
	int		j;
	int x_pox;

	i = -1;
	width = spr->h / spr->txt.height;
	while (++i < spr->txt.width - 1)
	{
		j = -1;
		while (++j < width)
		{
			x_pox = (int)(spr->x_strt + i * width + j);
			if (x_pox >= 0  && x_pox <= game->settings.w - 1
			&& spr->dist < (game->player.rays[x_pox]->line.size / game->minimap_tile.size)
			 * game->cube_size)
				draw_sprt_strip(game, spr, i, x_pox);
		}
	}

}
void	draw_sprites(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->sprs_num)
	{
		if (game->sprs[i]->visible)
			draw_sprt(game, game->sprs[i]);
	}
}
