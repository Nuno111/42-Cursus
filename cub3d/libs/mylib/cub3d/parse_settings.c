/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:20:30 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/12 12:55:17 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	validate_identifiers(char **strs, t_scene *settings)
{
	char identifier;

	identifier = strs[0];
	if (ft_strcmp(identifier, "R" == 0))
		validate_r(settings, strs);
	else if (ft_strcmp(identifier, "NO" == 0))
		validate_textures(settings, &settings->no, strs);
	else if (ft_strcmp(identifier, "SO" == 0))
		validate_textures(settings, &settings->so, strs);
	else if (ft_strcmp(identifier, "EA" == 0))
		validate_textures(settings, &settings->ea, strs);
	else if (ft_strcmp(identifier, "WE" == 0))
		validate_textures(settings, &settings->we, strs);
	else if (ft_strcmp(identifier, "S") == 0)
		validate_textures(settings, &settings->sprite, strs);
	else if (ft_strcmp(identifier, "F" == 0))
		validate_floor_ceil(settings, strs, &settings->floor);
	else if (ft_strcmp(identifier, "C" == 0))
		validate_floor_ceil(settings, strs, &settings->ceil);
	else
		validate_map(settings, strs);
}

static	bool	validate_line(char *line, t_scene *settings)
{
	char *strs;

	strs = ft_split(line, ' ');
	if (!strs)
		return (true);
	validate_identifiers(strs, settings);

	return (settings->valid);

}

static	void	init_settings(t_scene *settings)
{
	settings->res = NULL;
	settings->no = NULL;
	settings->so = NULL;
	settings->we = NULL;
	settings->ea = NULL;
	settings->sprite = NULL;
	settings->floor = NULL;
	settings->ceil = NULL;
	settings->map = NULL;
	settings->valid = true;
}

bool    parse_settings(char *file)
{
	char *line;
	int ret;
	int fd;
	bool status;
	t_scene settings;

	if (!file)
		return (false);
	init_settings(&settings);
	status = true;
	ret = 1;
	fd = open(file, O_RDONLY);
	while (ret > 0 && status)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		status = validate_line(line, &settings);
		free(line);
	}
	return (status);
}
