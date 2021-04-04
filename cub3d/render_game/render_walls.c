/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:07:47 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/04 22:01:51 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_walls(t_game *game)
{
	t_texture n_wall;

	n_wall.relative_path = game->settings.no;
	printf("%s\n", n_wall.relative_path);
	n_wall.img = mlx_xpm_file_to_image(game->vars.mlx, n_wall.relative_path, &n_wall.width, &n_wall.height);
	printf(" Width: %d, Height: %d\n",n_wall.width, n_wall.height);
	printf("%d\n", ((int )n_wall.img[1]));
}
