/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:21:32 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/21 20:05:26 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	validate_string(char *str)
{
	int i;
	int	num;
	int comma;

	if (!str)
		return (false);
	i = 0;
	num = 0;
	comma = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			num++;
		else if (str[i] == ',' && num <= 3)
		{
			comma++;
			num = 0;
		}
		else if (str[i] == ',')
			return (false);
		if (comma > 2 || num > 3 || (!ft_isdigit(str[i]) && str[i] != ','))
			return (false);
		i++;
	}
	return (true);

}

void	init_settings(t_scene *settings)
{
	settings->res = NULL;
	settings->no = NULL;
	settings->so = NULL;
	settings->we = NULL;
	settings->ea = NULL;
	settings->sprite = NULL;
	settings->floor = NULL;
	settings->ceil = NULL;
	settings->tmp_map = NULL;
	settings->map = NULL;
	settings->map_width = 0;
	settings->map_size = 0;
	settings->line = NULL;
}

void	free_settings(t_scene *settings)
{
	if (settings->res)
		free(settings->res);
	if (settings->no)
		free(settings->no);
	if (settings->so)
		free(settings->so);
	if (settings->we)
		free(settings->we);
	if (settings->ea)
		free(settings->ea);
	if (settings->sprite)
		free(settings->sprite);
	if (settings->floor)
		free(settings->floor);
	if (settings->ceil)
		free(settings->ceil);
	if (settings->tmp_map)
		ft_free_list(&settings->tmp_map);
	if (settings->map)
		ft_freearrays(settings->map);
	if (settings->line)
		free(settings->line);
}
