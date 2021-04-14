/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:09:52 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/14 14:26:23 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	get_max_width(t_scene *settings)
{
	int		i;
	size_t	curr_width;

	i = 0;
	while (settings->map[i])
	{
		curr_width = ft_strlen(settings->map[i]);
		if (curr_width > settings->map_width)
			settings->map_width = curr_width;
		i++;
	}
}

static	void	adjust_line_to_width(t_scene *settings)
{
	size_t	i;
	int		diff;

	i = 0;
	while (settings->map[i])
	{
		diff = settings->map_width - ft_strlen(settings->map[i]);
		while (diff > 0)
		{
			ft_add_letter(' ', &settings->map[i], false);
			diff--;
		}
		i++;
	}
	i = 0;
	while (settings->map[i])
	{
		ft_add_letter('+', &settings->map[i], true);
		ft_add_letter('+', &settings->map[i], false);
		i++;
	}
}

static	void	create_fake_line(t_scene *settings, char **fake_map, int i)
{
	fake_map[i] = malloc(sizeof(char) * (settings->map_width + 1));
	if (!fake_map[i])
		error_and_exit_settings(settings, "Error\nThere was a problem when allocating memory for the map.");
	ft_memset(fake_map[i], '+', settings->map_width);
	fake_map[i][settings->map_width] = '\0';
}

static	void	finish_fake_map(t_scene *settings, char **fake_map)
{
	size_t i;

	get_max_width(settings);
	create_fake_line(settings, fake_map, 0);
	create_fake_line(settings, fake_map, settings->map_size + 1);
	fake_map[settings->map_size + 2] = NULL;
	i = 0;
	while (settings->map[i])
	{
		fake_map[i + 1] = ft_strdup(settings->map[i]);
		i++;
	}
}

void	create_fake_map(t_scene *settings)
{
	char		**fake_map;

	get_max_width(settings);
	adjust_line_to_width(settings);
	while (settings->map[settings->map_size])
		(settings->map_size)++;
	if (settings->map_size == 0)
		error_and_exit_settings(settings, "Error\nMap doesn't exist.");
	fake_map = malloc(sizeof(char *) * (settings->map_size + 3));
	if (!fake_map)
		error_and_exit_settings(settings, "Error\nThere was a problem when allocating memory for the map.");
	finish_fake_map(settings, fake_map);
	ft_freearrays(settings->map);
	settings->map = fake_map;
	while (settings->map[settings->map_size])
		settings->map_size++;
}
