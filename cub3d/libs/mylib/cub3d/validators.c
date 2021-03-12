/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:22:37 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/12 12:00:10 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_r(t_scene *settings, char **strs)
{
	t_res *resolution;

	if (!settings->res)
	{
		if (ft_str_is_numeric(strs[1]) && ft_str_is_numeric(strs[2]))
		{
			resolution = malloc(sizeof(t_res));
			if (!resolution)
				return ;
			resolution->x = ft_atoi(strs[1]);
			resolution->y = ft_atoi(strs[2]);
		}
	}
	if (!resolution || resolution->x <= 0 || resolution->y <= 0)
		settings->valid = false;
	else
		settings->res = resolution;
}

void	validate_s(t_scene *settings, char **strs)
{
	if (settings->sprite)
	{
		settings->valid = false;
		return ;
	}

}

void	validate_f(t_scene *settings, char **strs)
{
	if (settings->floor)
	{
		settings->valid = false;
		return ;
	}

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
