/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:20:30 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/18 12:38:20 by ngregori         ###   ########.fr       */
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
		error_and_exit(settings, "Error when parsing map, forbidden character found");
}

static	void	verify_identifiers(char **strs, t_scene *settings)
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

static	void	parse_line(char *line, t_scene *settings)
{
	char **strs;

	if (*line == '\0')
		return ;
	if (settings->res && settings->no && settings->ea && settings->we
	&& settings->so && settings->sprite && settings->floor && settings->ceil)
		parse_map(line, settings);
	else
	{
		strs = ft_split(line, ' ');
		verify_identifiers(strs, settings);
		ft_freearrays(strs);
	}
}

void    parse_settings(t_scene *settings, char *file)
{
	char *line;
	int ret;
	int fd;

	if (!validate_name(file))
		error_and_exit(settings, "Invalid name. File must end with .cub");
	ret = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_and_exit(settings, "Could not open the file for reading");
	while (ret > 0)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		parse_line(line, settings);
		free(line);
	}
	validate_map(settings);
	close(fd);
}
