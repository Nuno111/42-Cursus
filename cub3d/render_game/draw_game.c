/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:05:49 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/13 15:02:11 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	draw_wall_line(t_game *game, t_wall wall)
{
	int j;
	int	texture_x;
	int i;

	i = 0;
	while (i < wall.size)
	{
		j = 0;
		texture_x = (int)fmod(wall.x, wall.texture.width);
		wall.color = wall.texture.addr[texture_x + j * wall.texture.line_length];
		while (j < wall.size / game->cube_size)
		{
			my_mlx_pixel_put(&game->main_img, wall.x, wall.y + j + i, wall.color);
			j++;
		}
	i++;
	}
}

void	draw_walls(t_game *game)
{
	int i;
	t_wall wall;

	i = 0;
	wall.ang = (M_PI / 2);
	while (i < game->player.num_rays)
	{
		wall.size = get_wall_height(game, game->player.rays[i]);
		if (wall.size > game->settings.res->y)
			wall.size = game->settings.res->y;
		if (wall.y < 0)
			wall.y = 0;
		wall.x = i;
		wall.y = (game->settings.res->y / 2) - (wall.size / 2);
		wall.texture = assign_wall_texture(game, *game->player.rays[i]);
		draw_wall_line(game, wall);
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
