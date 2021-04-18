/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:05:49 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/18 16:50:26 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_wall_pixel(t_game *game, t_wall wall, int height, int i)
{
	int	x;
	double	scaled_x;
	t_color color;

	scaled_x = (game->player.rays[i]->texture_pixel / game->minimap_tile.size) * game->cube_size;
	x = (int)fmod(scaled_x, game->cube_size);
	if (wall.texture.endian == 1)
	{
		color.t = wall.texture.addr[x + height * wall.texture.line_length];
		color.r = wall.texture.addr[x + 1 + height * wall.texture.line_length];
		color.g = wall.texture.addr[x + 2 + height * wall.texture.line_length];
		color.b = wall.texture.addr[x + 3 + height * wall.texture.line_length];
	}
	else
	{
		color.t = wall.texture.addr[x + 3 + height * wall.texture.line_length];
		color.r = wall.texture.addr[x + 2 + height * wall.texture.line_length];
		color.g = wall.texture.addr[x + 1 + height * wall.texture.line_length];
		color.b = wall.texture.addr[x + height * wall.texture.line_length];
	}
	color.trgb = create_trgb(color.t, color.r, color.g, color.b);
	return (color.trgb);
}

static	void	draw_wall_line(t_game *game, t_wall wall, double height, int ray_index)
{
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
		if (wall.size > game->settings.res->y)
			wall.size = game->settings.res->y;
		if (wall.y < 0)
			wall.y = 0;
		wall.x = i;
		wall.y = (game->settings.res->y / 2) - (wall.size / 2);
		wall.texture = assign_wall_texture(game, *game->player.rays[i]);
		draw_wall_line(game, wall, height, i);
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
			draw_square(&game->main_img, game->minimap_tile);
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
		draw_line(&game->main_img, game->player.rays[i]->line);
}
