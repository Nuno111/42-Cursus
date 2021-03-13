/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:25:30 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/13 21:56:17 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(char *line, t_scene *settings)
{
	int		i;
	char	*valid;

	i = 0;
	while (line[i])
	{
		valid = ft_strchr("012NSEW ", line[i]);
		if (!valid)
			break;
		i++;
	}
	if (valid)
		ft_lstadd_back(&settings->map, ft_lstnew(ft_strdup(line)));
	else
		settings->valid = false;
}
