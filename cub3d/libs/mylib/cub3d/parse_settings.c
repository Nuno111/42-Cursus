/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:20:30 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/15 19:41:08 by ngregori         ###   ########.fr       */
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
		valid = ft_strchr("012NSEW ", line[i]);
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
		settings->valid = false;
}

static	void	validate_identifiers(char **strs, t_scene *settings)
{
	char *identifier;

	identifier = strs[0];
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
}

static	bool	parse_line(char *line, t_scene *settings)
{
	char **strs;

	if (*line == '\0')
		return (settings->valid);
	if (settings->res && settings->no && settings->ea && settings->we
	&& settings->so && settings->sprite && settings->floor && settings->ceil)
		parse_map(line, settings);
	else
	{
		strs = ft_split(line, ' ');
		validate_identifiers(strs, settings);
		ft_freearrays(strs);
	}
	return (settings->valid);
}

bool    parse_settings(t_scene *settings, char *file)
{
	char *line;
	int ret;
	int fd;
	bool status;

	if (!file || !validate_name(file))
		return (false);
	status = true;
	ret = 1;
	fd = open(file, O_RDONLY);
	while (ret > 0 && status)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		status = parse_line(line, settings);
		free(line);
	}
	validate_map(settings);
	close(fd);
	return (status);
}
