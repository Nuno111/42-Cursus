/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:22:37 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/28 09:30:32 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_r(t_scene *settings, char **strs)
{
	if (!strs[1] || !strs[2] || strs[3] || settings->width)
		error_and_exit_settings(settings, "Error\nProblem when handling resolution.");
	if (ft_str_is_numeric(strs[1]) && ft_str_is_numeric(strs[2]))
	{
		settings->width = ft_atoi(strs[1]);
		settings->height = ft_atoi(strs[2]);
		if (settings->width <= 0 || settings->width > 1920 || settings->height <= 0 || settings->height > 1080)
			error_and_exit_settings(settings, "Error\nInvalid input for window resolution.");
	}
	else
		error_and_exit_settings(settings, "Error\nInvalid string format when checking resolution values.");
}

void	validate_floor_ceil(t_scene *settings, t_color **floor_or_ceil, char **strs)
{
	t_color	*tmp;
	char	**tmp_strs;

	tmp = NULL;
	if (*floor_or_ceil || !validate_string(strs[1]) || strs[2])
		error_and_exit_settings(settings, "Error\nString is not properly formatted.");
	tmp_strs = ft_split(strs[1], ',');
	if (!tmp_strs[0] || !tmp_strs[1] || !tmp_strs[2])
		error_and_exit_settings(settings, "Error\nProblem found when handling floor or ceiling, 3 color values are needed.");
	if (ft_str_is_numeric(tmp_strs[0]) && ft_str_is_numeric(tmp_strs[1]) && ft_str_is_numeric(tmp_strs[2]))
		tmp = malloc(sizeof(t_color));
	if (tmp)
	{
		tmp->r = ft_atoi(tmp_strs[0]);
		tmp->g = ft_atoi(tmp_strs[1]);
		tmp->b = ft_atoi(tmp_strs[2]);
		if (tmp->r >= 0 && tmp->r <= 255 && tmp->g >= 0 && tmp->g <= 255 &&tmp->b >= 0 && tmp->b <= 255)
			*floor_or_ceil = tmp;
		else
			error_and_exit_settings(settings, "Error\nOnly values between 0 and 255 are valid.");
	}
	else
		error_and_exit_settings(settings, "Error\nInvalid string format when checking floor/ceiling values.");
	ft_freearrays(tmp_strs);
}

void	validate_textures(t_scene *settings, char **path, char **strs)
{
	char	*tmp;
	size_t	len;
	int	validate_file;
	char	*trimmed;

	if (!strs[1] || *path)
		error_and_exit_settings(settings, "Error\nProblem found when handling path to textures.");
	tmp = ft_strdup(strs[1]);
	if (!tmp)
		error_and_exit_settings(settings, "Error\nProblem found when handling path to textures.");
	*path = tmp;
	trimmed = ft_strtrim(*path, " \n\t\v\f\r");
	len = ft_strlen(trimmed);
	if (trimmed[len - 1] != 'm' || trimmed[len - 2] != 'p' || trimmed[len - 3] != 'x' || tmp[len - 4] != '.')
	{
		free(trimmed);
		error_and_exit_settings(settings, "Error\nProblem found when handling path to textures.");
	}
	validate_file = open(trimmed, O_RDONLY);
	free(trimmed);
	if (validate_file == -1)
		error_and_exit_settings(settings, "Error\nProblem found with texture path, could not open file for reading");
	close(validate_file);
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
