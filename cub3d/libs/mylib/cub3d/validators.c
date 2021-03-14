/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:22:37 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/14 17:12:12 by ngregori         ###   ########.fr       */
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
		resolution = malloc(sizeof(t_res));
	if (resolution)
	{
		resolution->x = ft_atoi(strs[1]);
		resolution->y = ft_atoi(strs[2]);
		if (resolution->x <= 0 || resolution->y <= 0)
			settings->valid = false;
		else
			settings->res = resolution;
	}
	else
		settings->valid = false;
}

void	validate_floor_ceil(t_scene *settings, t_rgb **floor_or_ceil, char **strs)
{
	t_rgb *tmp;

	if (!strs[1] || !strs[2] || !strs[3] || *floor_or_ceil)
	{
		settings->valid = false;
		return ;
	}
	if (ft_str_is_numeric(strs[1]) && ft_str_is_numeric(strs[2]) && ft_str_is_numeric(strs[3]))
		tmp = malloc(sizeof(t_rgb));
	if (tmp)
	{
		tmp->r = (unsigned char)ft_atoi(strs[1]);
		tmp->g = (unsigned char)ft_atoi(strs[2]);
		tmp->b = (unsigned char)ft_atoi(strs[3]);
		*floor_or_ceil = tmp;
	}
	else
		settings->valid = false;
}

void	validate_textures(t_scene *settings, char **path, char **strs)
{
	char *tmp;

	if (!strs[1] || *path)
	{
		settings->valid = false;
		return ;
	}
	tmp = ft_strdup(strs[1]);
	if (tmp)
		*path = tmp;
	else
		settings->valid = false;
}

bool    validate_name(char *file)
{
	char	*index;
	char	*valid;
	int		i;

	i = 1;
	valid = ".cub";
	if (file)
	{
		index = ft_strchr(file, '.');
		if (index)
		{
			while (index[i] == valid[i] && index[i])
					i++;
		}
		if (valid[i] == '\0')
			return (true);
	}
    return (false);
}

void	validate_map(t_scene *settings)
{
	if (!settings->valid)
		return ;
	linked_to_array(settings);
	verify_position(settings);
	verify_walls(settings);
}
