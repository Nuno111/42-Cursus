/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:29:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/05/14 17:46:27 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall(double x, double y, t_game *game)
{
	size_t	index_w;
	size_t	index_h;
	char	c;

	index_w = x / game->mmt.size;
	index_h = y / game->mmt.size;
	if (index_w >= game->stg.map_width || index_h >= game->stg.map_size)
		return (false);
	c = game->stg.map[index_h][index_w];
	if (c == '1')
		return (true);
	return (false);
}

bool	is_sprite(double x, double y, t_game *game)
{
	size_t	index_w;
	size_t	index_h;
	char	c;

	index_w = x / game->mmt.size;
	index_h = y / game->mmt.size;
	if (index_w >= game->stg.map_width || index_h >= game->stg.map_size)
		return (false);
	c = game->stg.map[index_h][index_w];
	if (c == '2')
		return (true);
	return (false);
}
