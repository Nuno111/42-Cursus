/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:20:30 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/16 22:16:58 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	parse_map(char *line, t_scene *settings)
{
	int		i;
	char	*valid;
	t_list	*node;
	i = 0;
	while (line[i])
	{
		valid = ft_strchr("012NSEW\t ", line[i]);
		if (!valid)
			break;
		i++;
	}
	if (valid)
	{
		node = ft_lstnew(ft_strdup(line));
		ft_lstadd_back(&settings->tmp_map, node);
	}
	else
		error_and_exit_settings(settings, "Error\nForbidden character found when parsing map.");
}

static	void	verify_identifiers(char **strs, t_scene *settings)
{
	char *identifier;

	identifier = strs[0];
	if (!identifier || !strs[1])
		error_and_exit_settings(settings, "Error\nProblem found when handling paths.");
	if (ft_strcmp(identifier, "R") == 0)
		validate_r(settings, strs);
	else if (ft_strcmp(identifier, "NO") == 0)
		validate_textures(settings, &settings->no, strs);
	else if (ft_strcmp(identifier, "SO") == 0)
		validate_textures(settings, &settings->so, strs);
	else if (ft_strcmp(identifier, "EA") == 0)
		validate_textures(settings, &settings->ea, strs);
	else if (ft_strcmp(identifier, "WE") == 0)
		validate_textures(settings, &settings->we, strs);
	else if (ft_strcmp(identifier, "S") == 0)
		validate_textures(settings, &settings->sprite, strs);
	else if (ft_strcmp(identifier, "F") == 0)
		validate_floor_ceil(settings, &settings->floor, strs);
	else if (ft_strcmp(identifier, "C") == 0)
		validate_floor_ceil(settings, &settings->ceil, strs);
	else
		error_and_exit_settings(settings, "Error\nInvalid string found when parsing map settings.");
}

static	void	parse_line(t_scene *settings)
{
	char **strs;
	char	*trimmed;

	if (*settings->line == '\0')
		return ;
	if (settings->res && settings->no && settings->ea && settings->we
	&& settings->so && settings->sprite && settings->floor && settings->ceil)
		parse_map(settings->line, settings);
	else
	{
		trimmed = ft_strtrim(settings->line, " \n\t\v\f\r");
		free(settings->line);
		settings->line = trimmed;
		strs = ft_split(settings->line, ' ');
		verify_identifiers(strs, settings);
		ft_freearrays(strs);
	}
}

void    parse_settings(t_scene *settings, char *file)
{
	int ret;
	int fd;

	if (!validate_name(file))
		error_and_exit_settings(settings, "Error\nInvalid name. File must end with .cub.");
	ret = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_and_exit_settings(settings, "Error\nCould not open the file for reading.");
	while (ret > 0)
	{
		ret = get_next_line(fd, &settings->line);
		parse_line(settings);
		free(settings->line);
		settings->line = NULL;
	}
	validate_map(settings);
	close(fd);
}
