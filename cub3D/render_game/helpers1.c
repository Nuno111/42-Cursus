/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:29:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/22 02:16:22 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall(double x, double y, t_game *game)
{
	size_t index_w;
	size_t index_h;
	char	c;

	index_w = x / game->minimap_tile.size;
	index_h = y / game->minimap_tile.size;
	if (index_w >= game->settings.map_width || index_h >= game->settings.map_size)
		return (false);
	c = game->settings.map[index_h][index_w];
	if (c == '1')
		return (true);
	return (false);
}

bool	is_sprite(double x, double y, t_game *game)
{
	size_t index_w;
	size_t index_h;
	char	c;

	index_w = x / game->minimap_tile.size;
	index_h = y / game->minimap_tile.size;
	if (index_w >= game->settings.map_width || index_h >= game->settings.map_size)
		return (false);
	c = game->settings.map[index_h][index_w];
	if (c == '2')
		return (true);
	return (false);
}
