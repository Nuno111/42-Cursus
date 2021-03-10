/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:20:30 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/10 20:41:29 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	bool	handle_line(char *line)
{
	char *strs;

	strs = ft_split(line, ' ');
	if (!strs)
		return (true);

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
	status = true;
	ret = 1;
	fd = open(file, O_RDONLY);
	while (ret > 0 && status)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		status = handle_line(line);
		free(line);
	}
	return (status);
}
