/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:34:11 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/16 21:57:42 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_game.h"

void	render_minimap(t_scene *settings, void *mlx)
{
	void	*mlx_win;

	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world");
	mlx_loop(mlx);
}

void    render_game(t_scene *settings)
{
	void	*mlx;

	mlx = mlx_init();

	render_minimap(settings, mlx);
}
