/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:22:37 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/24 10:46:50 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_r(t_scene *settings, char **strs)
{
	t_res *resolution;

	if (!strs[1] || !strs[2] || settings->res)
		error_and_exit(settings, "Error with handling resolution");
	if (ft_str_is_numeric(strs[1]) && ft_str_is_numeric(strs[2]))
		resolution = malloc(sizeof(t_res));
	if (resolution)
	{
		resolution->x = ft_atoi(strs[1]);
		resolution->y = ft_atoi(strs[2]);
		if (resolution->x <= 0 || resolution->y <= 0)
			error_and_exit(settings, "Only positive values for x and y are valid for resolution");
		else
			settings->res = resolution;
	}
	else
		error_and_exit(settings, "Invalid string format when checking resolution values");
}

void	validate_floor_ceil(t_scene *settings, t_rgb **floor_or_ceil, char **strs)
{
	t_rgb	*tmp;
	char	**tmp_strs;

	if (!strs[1] || *floor_or_ceil)
		error_and_exit(settings, "Error found when handling floor or ceiling values");
	tmp_strs = ft_split(strs[1], ',');
	if (!tmp_strs[0] || !tmp_strs[1] || !tmp_strs[2])
		error_and_exit(settings, "Error found when handling floor or ceiling, 3 color values are needed");
	if (ft_str_is_numeric(tmp_strs[0]) && ft_str_is_numeric(tmp_strs[1]) && ft_str_is_numeric(tmp_strs[2]))
		tmp = malloc(sizeof(t_rgb));
	if (tmp)
	{
		tmp->r = (unsigned char)ft_atoi(tmp_strs[0]);
		tmp->g = (unsigned char)ft_atoi(tmp_strs[1]);
		tmp->b = (unsigned char)ft_atoi(tmp_strs[2]);
		*floor_or_ceil = tmp;
	}
	else
		error_and_exit(settings, "Invalid string format when checking floor/ceiling values");
	ft_freearrays(tmp_strs);
}

void	validate_textures(t_scene *settings, char **path, char **strs)
{
	char *tmp;

	if (!strs[1] || *path)
		error_and_exit(settings, "Error found when handling path to textures");
	tmp = ft_strdup(strs[1]);
	if (tmp)
		*path = tmp;
	else
		error_and_exit(settings, "Error found when handling path to textures");
}

bool    validate_name(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len <= 4)
		return (false);
	if (file[len - 1] == 'b' && file[len - 2] == 'u'
	&& file[len - 3] == 'c' && file[len - 4] == '.')
		return (true);
	return (false);
}

void	validate_map(t_scene *settings)
{
	settings->map = linked_to_array(settings, settings->tmp_map);
	verify_position(settings);
	create_fake_map(settings);
	verify_walls(settings, settings->map);
}
