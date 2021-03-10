/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:20:51 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/10 19:09:27 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool    parse_name(char *map)
{
	char	*index;
	char	*valid;
	int		i;

	i = 1;
	valid = ".cub";
	if (map)
	{
		index = ft_strchr(map, '.');
		if (index)
		{
			while (index[i] == valid[i])
					i++;
		}
		if (valid[i] == '\0')
			return (true);
	}
    return (false);
}
