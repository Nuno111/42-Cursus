/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:20:30 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/10 20:55:47 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	bool	handle_line(char *line, t_scene *settings)
{
	char *strs;

	strs = ft_split(line, ' ');
	if (!strs)
		return (true);

}

static	void	init_settings(t_scene *settings)
{
	settings->res.x = 0;
	settings->res.y = 0;
	settings->no = NULL;
	settings->so = NULL;
	settings->we = NULL;
	settings->ea = NULL;
	settings->sprite = NULL;
	settings->floor = NULL;
	settings->ceil = NULL;
	settings->map = NULL;
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
		status = handle_line(line, &settings);
		free(line);
	}
	return (status);
}
