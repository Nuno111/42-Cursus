/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:34:11 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/20 17:56:44 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	square(t_data *data)
{
	int x;
	int y;
	unsigned color;

	y = 0;
	color = 0xFAFFFF00;
	while (y < 200)
	{
		x = 0;
		while (x < 200)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

int	key_hook(int keycode, char *msg)
{
	printf("%s%d\n", msg, keycode);
	return (0);
}

int		mouse_hook(int btn, int x, int y, void *param)
{
	printf("%s%d %d\n", (char *)param, x, y);
	printf("No btn was clicked %d\n", btn);
	return (0);
}

int	close_win(int keycode, t_vars *var)
{
	printf("%d\n", keycode);
	mlx_destroy_window(var->mlx, var->win);
	return (0);
}

void    render_game(t_scene *settings)
{
	t_data	img;
	t_vars var;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, settings->res->x, settings->res->y, "CUB3D");
	img.img = mlx_new_image(var.mlx, settings->res->x, settings->res->y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	square(&img);
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_hook(var.win, 2, 1L<<0, close_win, &var);
	mlx_loop(var.mlx);
}
