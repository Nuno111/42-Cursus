/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:05:49 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/19 18:33:06 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		get_bitmap_offset(t_game *game, int i, int bitmap_width)
{
	double	remainder;
	int		offset;

	remainder = game->player.rays[i]->texture_pixel - floor(game->player.rays[i]->texture_pixel);
	offset = bitmap_width * remainder;
	return (offset);
}

static	void	draw_wall_line(t_game *game, t_wall wall,int ray_index)
{
	int		y;
	int		y_tex;
	int		x_tex;
	double	step;
	double	tex_pox;

	step = 1.0 * wall.texture.height / wall.size;
	tex_pox = (wall.y - game->settings.res->height / 2 + wall.size / 2) * step;
	x_tex = get_bitmap_offset(game, ray_index, wall.texture.width);
	y = -1;
	while (++y < wall.size && y < game->settings.res->height)
	{
		y_tex = (int)tex_pox & (wall.texture.height - 1);
		tex_pox += step;
		game->main_img.addr[(wall.y * game->settings.res->width) + (y * game->settings.res->width)
			+ wall.x] = 0xffffff;//wall.texture.addr[y_tex * wall.texture.height + x_tex];
	}
}

void	draw_walls(t_game *game)
{
	int i;
	t_wall wall;
	double height;

	i = 0;
	while (i < game->player.num_rays)
	{
		height = get_wall_height(game, game->player.rays[i]);
		wall.size = height;
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

	height = 0;
	while (settings->map[height])
	{
		width = 0;
		while (settings->map[height][width])
		{
			if (settings->map[height][width] == '1')
				game->minimap_tile.color = 0x000080;
			else if (settings->map[height][width] == '0' || ft_strchr("NESW", settings->map[height][width]))
				game->minimap_tile.color = 0xFFFF00;
			else
				game->minimap_tile.color = 0x000000;
			game->minimap_tile.x = width * game->minimap_tile.size;
			game->minimap_tile.y = height * game->minimap_tile.size;
			draw_square(&game->main_img, game->minimap_tile, game->settings.res->height);
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
		draw_line(&game->main_img, game->player.rays[i]->line, game->settings.res->height);
}
