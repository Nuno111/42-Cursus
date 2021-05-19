/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:22:37 by ngregori          #+#    #+#             */
/*   Updated: 2021/05/19 18:21:44 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_r(t_scene *stg, char **strs)
{
	if (!strs[1] || !strs[2] || strs[3] || stg->w)
		error_and_exit_stg(stg, "Error\nProblem when handling resolution.");
	if (ft_str_is_numeric(strs[1]) && ft_str_is_numeric(strs[2]))
	{
		stg->w = ft_atoi(strs[1]);
		stg->h = ft_atoi(strs[2]);
		if (stg->w <= 0 || stg->w > 1920 || stg->h <= 0 || stg->h > 1080)
			error_and_exit_stg(stg, "Error\nInvalid input for resolution.");
	}
	else
		error_and_exit_stg(stg, "Error\nInvalid string format");
}

void	validate_floor_ceil(t_scene *stg, t_color **floor_or_ceil, char **strs)
{
	t_color	*tmp;
	char	**tmp_strs;

	tmp = NULL;
	if (*floor_or_ceil || !validate_string(strs[1]) || strs[2])
		error_and_exit_stg(stg, "Error\nString is not properly formatted.");
	tmp_strs = ft_split(strs[1], ',');
	if (!tmp_strs[0] || !tmp_strs[1] || !tmp_strs[2])
		error_and_exit_stg(stg, "Error\n3 color values are needed.");
	if (ft_str_is_numeric(tmp_strs[0]) && ft_str_is_numeric(tmp_strs[1])
		&& ft_str_is_numeric(tmp_strs[2]))
		tmp = malloc(sizeof(t_color));
	if (tmp)
	{
		tmp->r = ft_atoi(tmp_strs[0]);
		tmp->g = ft_atoi(tmp_strs[1]);
		tmp->b = ft_atoi(tmp_strs[2]);
		if (tmp->r >= 0 && tmp->r <= 255 && tmp->g >= 0 && tmp->g <= 255
			&& tmp->b >= 0 && tmp->b <= 255)
			*floor_or_ceil = tmp;
		else
			error_and_exit_stg(stg, "Error\nValues must be between 0 and 255");
	}
	else
		error_and_exit_stg(stg, "Error\nInvalid string format.");
	ft_freearrays(tmp_strs);
}

void	validate_textures(t_scene *stg, char **path, char **strs)
{
	char	*tmp;
	size_t	len;
	int	validate_file;
	char	*trimmed;

	if (!strs[1] || *path)
		error_and_exit_stg(stg, "Error\nProblem found when handling path to textures.");
	tmp = ft_strdup(strs[1]);
	if (!tmp)
		error_and_exit_stg(stg, "Error\nProblem found when handling path to textures.");
	*path = tmp;
	trimmed = ft_strtrim(*path, " \n\t\v\f\r");
	len = ft_strlen(trimmed);
	if (trimmed[len - 1] != 'm' || trimmed[len - 2] != 'p' || trimmed[len - 3] != 'x' || tmp[len - 4] != '.')
	{
		free(trimmed);
		error_and_exit_stg(stg, "Error\nProblem found when handling path to textures.");
	}
	validate_file = open(trimmed, O_RDONLY);
	free(trimmed);
	if (validate_file == -1)
		error_and_exit_stg(stg, "Error\nProblem found with texture path, could not open file for reading");
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

void	validate_map(t_scene *stg)
{
	stg->map = linked_to_array(stg, stg->tmp_map);
	verify_position(stg);
	create_fake_map(stg);
	verify_walls(stg, stg->map);
}
