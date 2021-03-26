/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:34:11 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/26 12:30:17 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    render_game(t_scene *settings)
{
	t_data	img;
	t_vars var;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, settings->res->x, settings->res->y, "CUB3D");
	img.img = mlx_new_image(var.mlx, settings->res->x, settings->res->y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	create_minimap(settings, &img);
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_key_hook(var.win, handle_key_press, &var);
	mlx_loop(var.mlx);
}
