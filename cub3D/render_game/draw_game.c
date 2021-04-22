/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:05:49 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/22 01:43:09 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_ceil(t_game *game, t_rgb colour, bool floor)
{
	int	x;
	int	y;
	int max;
	t_color	color;

	if (floor)
	{
		max = game->settings.res->height / 2;
		y = -1;	
	}
	else
	{
		max = game->settings.res->height;
		y = game->settings.res->height / 2 - 1;
	}
	color.trgb = create_trgb(0, colour.r, colour.g, colour.b);
	while (++y < max)
	{
		x = -1;
		while (++x < game->settings.res->width)
			game->main_img.addr[x + y * game->settings.res->width] = color.trgb;
	}
}
static	void	draw_wall_line(t_game *game, t_wall wall, int ray_index)
{
	int		y;
	int		y_tex;
	int		x_tex;
	double	step;
	double	tex_pox;

	step = wall.texture.height / wall.size;
	tex_pox = (wall.y - game->settings.res->height / 2 + wall.size / 2) * step;
	x_tex = fmod((game->player.rays[ray_index]->texture_pixel / game->minimap_tile.size) * game->cube_size, wall.texture.width - 1);
	y = -1;
	while (++y < wall.size && y < game->settings.res->height)
	{
		y_tex = (int)tex_pox & (wall.texture.height - 1);
		game->main_img.addr[wall.x + (wall.y + y) * game->settings.res->width] = wall.texture.addr[y_tex * wall.texture.height + x_tex];
		tex_pox += step;
	}
}

void	draw_walls(t_game *game)
{
	int i;
	t_wall wall;

	i = 0;
	while (i < game->player.num_rays)
	{
		wall.size = get_wall_height(game, game->player.rays[i]);
		wall.x = i;
		wall.y = (game->settings.res->height / 2) - (wall.size / 2);
		if (wall.y < 0)
			wall.y = 0;
		wall.texture = assign_wall_texture(game, *game->player.rays[i]);
		draw_wall_line(game, wall, i);
		i++;
	}
}

void	draw_minimap(t_scene *settings, t_game *game)
{
	int width;
	int height;

	height = 1;
	while (settings->map[height + 1])
	{
		width = 1;
		while (settings->map[height][width + 1])
		{
			if (settings->map[height][width] == '1')
				game->minimap_tile.color = 0x293250;
			else if (settings->map[height][width] == '0' || ft_strchr("NESW", settings->map[height][width]))
				game->minimap_tile.color = 0xFFD55A;
			else
				game->minimap_tile.color = 0x001FFF;
			game->minimap_tile.x = width * game->minimap_tile.size;
			game->minimap_tile.y = height * game->minimap_tile.size;
			draw_square(&game->main_img, game->minimap_tile, game->settings.res->width);
			width++;
		}
		height++;
	}
}

void	draw_rays(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->player.num_rays)
		draw_line(&game->main_img, game->player.rays[i]->line, game->settings.res->width);
}
