/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:09:52 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/24 10:28:18 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	get_max_width(t_scene *settings, size_t *max_width)
{
	int		i;
	size_t	curr_width;

	i = 0;
	while (settings->map[i])
	{
		curr_width = ft_strlen(settings->map[i]);
		if (curr_width > *max_width)
			*max_width = curr_width;
		i++;
	}
}

static	void	adjust_line_to_width(t_scene *settings, size_t max_width)
{
	size_t	i;
	int		diff;

	i = 0;
	while (settings->map[i])
	{
		diff = max_width - ft_strlen(settings->map[i]);
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

static	void	create_fake_line(t_scene *settings, char **fake_map, int i, size_t max_width)
{
	fake_map[i] = malloc(sizeof(char) * (max_width + 1));
	if (!fake_map[i])
		error_and_exit(settings, "Error\nThere was a problem when allocating memory for the map");
	ft_memset(fake_map[i], '+', max_width);
	fake_map[i][max_width] = '\0';
}

static	void	finish_fake_map(t_scene *settings, char **fake_map, size_t *max_width, size_t arr_size)
{
	size_t i;

	get_max_width(settings, max_width);
	create_fake_line(settings, fake_map, 0, *max_width);
	create_fake_line(settings, fake_map, arr_size + 1, *max_width);
	fake_map[arr_size + 2] = NULL;
	i = 0;
	while (settings->map[i])
	{
		fake_map[i + 1] = ft_strdup(settings->map[i]);
		i++;
	}
}

void	create_fake_map(t_scene *settings, size_t *max_width, size_t *arr_size)
{
	char		**fake_map;
	int i = 0;

	get_max_width(settings, max_width);
	adjust_line_to_width(settings, *max_width);
	while (settings->map[*arr_size])
		(*arr_size)++;
	if (*arr_size == 0)
		error_and_exit(settings, "Error\nMap doesn't exist");
	fake_map = malloc(sizeof(char *) * (*arr_size + 3));
	if (!fake_map)
		error_and_exit(settings, "Error\nThere was a problem when allocating memory for the map");
	finish_fake_map(settings, fake_map, max_width, *arr_size);
	ft_freearrays(settings->map);
	settings->map = fake_map;
	while (settings->map[i])
	{
		printf("%s\n", settings->map[i]);
		i++;
	}
}
