/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:22:37 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/12 12:35:00 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_r(t_scene *settings, char **strs)
{
	t_res *resolution;

	if (!strs[1] || !strs[2] || settings->res)
	{
		settings->valid = false;
		return ;
	}
	if (ft_str_is_numeric(strs[1]) && ft_str_is_numeric(strs[2]))
	{
		resolution = malloc(sizeof(t_res));
		if (!resolution)
			return ;
		resolution->x = ft_atoi(strs[1]);
		resolution->y = ft_atoi(strs[2]);
	}
	if (resolution->x <= 0 || resolution->y <= 0)
		settings->valid = false;
	else
		settings->res = resolution;
}

void	validate_floor_ceil(t_scene *settings, t_rgb *floor_or_ceil, char **strs)
{
	t_rgb *tmp;

	if (!floor_or_ceil)
	{
		if (ft_str_is_numeric(strs[1]) && ft_str_is_numeric(strs[2]) && ft_str_is_numeric(strs[3]))
		{
			tmp = malloc(sizeof(t_rgb));
			if (!tmp)
				return ;
			tmp->r = (unsigned char)ft_atoi(strs[1]);
			tmp->g = (unsigned char)ft_atoi(strs[2]);
			tmp->b = (unsigned char)ft_atoi(strs[3]);
		}
	}
	if (!floor_or_ceil || tmp->r < 0 || tmp->g < 0 || tmp->b < 0)
		settings->valid = false;
	else
		floor_or_ceil = tmp;
}

void	validate_c(t_scene *settings, char **strs)
{
	if (settings->ceil)
	{
		settings->valid = false;
		return ;
	}

}

void	validate_texture(t_scene *settings, char **path, char **strs)
{

}
