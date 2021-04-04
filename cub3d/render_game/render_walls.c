/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:07:47 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/04 21:11:47 by ngregori         ###   ########.fr       */
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
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, n_wall.img, 600, 600);
}
