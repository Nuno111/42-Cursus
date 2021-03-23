/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:21:32 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/20 12:22:48 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void			error_and_exit(t_scene *settings, char *error_log)
{
	printf("%s.\n", error_log);
	free_settings(settings);
	exit(ERR);
}

void	init_settings(t_scene *settings)
{
	settings->res = NULL;
	settings->no = NULL;
	settings->so = NULL;
	settings->we = NULL;
	settings->ea = NULL;
	settings->sprite = NULL;
	settings->floor = NULL;
	settings->ceil = NULL;
	settings->tmp_map = NULL;
	settings->map = NULL;
	settings->valid = true;
}

void	free_settings(t_scene *settings)
{
	if (settings->res)
		free(settings->res);
	if (settings->no)
		free(settings->no);
	if (settings->so)
		free(settings->so);
	if (settings->we)
		free(settings->we);
	if (settings->ea)
		free(settings->ea);
	if (settings->sprite)
		free(settings->sprite);
	if (settings->floor)
		free(settings->floor);
	if (settings->ceil)
		free(settings->ceil);
	if (settings->tmp_map)
		ft_free_list(&settings->tmp_map);
	if (settings->map)
		ft_freearrays(settings->map);
}