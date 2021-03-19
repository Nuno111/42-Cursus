/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:34:11 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/19 14:57:45 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# include <mlx.h>
void    render_game(t_scene *settings)
{
	void	*mlx;

	mlx = mlx_init();


	mlx_new_window(mlx, settings->res->x, settings->res->y, "hello world");
	mlx_loop(mlx);
}
