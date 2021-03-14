/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:25:30 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/14 13:51:38 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	verify_position(t_scene *settings)
{
	int		i;
	int		j;
	bool	position_found;
	char	*valid_char;

	position_found = false;
	i = 0;
	while (settings->map[i])
	{
		j = 0;
		while (settings->map[i][j])
		{
			valid_char = ft_strchr("NESW", settings->map[i][j]);
			if (valid_char && !position_found)
				position_found = true;
			else if (valid_char)
			{
				settings->valid = false;
				return ;
			}
			j++;
		}
		i++;
	}
}

static	char	*replace_tabs(char *str)
{
	size_t	i;
	char	*new;
	char	*tmp;

	new = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\t')
			add_letter(str[i], &new);
		else
		{
			tmp = ft_strjoin(new, "    ");
			if (new)
				free(new);
			new = tmp;
		}
		i++;
	}
	return (new);
}

static	void	linked_to_array(t_scene *settings)
{
	int		size;
	char	**arr;
	int		i;
	t_list	*tmp_node;

	size = ft_lstsize(settings->tmp_map);
	arr = malloc(sizeof(char *) * size);
	if (!arr)
		return 	;
	while (settings->tmp_map)
	{
		tmp_node = settings->tmp_map;
		settings->tmp_map = settings->tmp_map->next;
		if (ft_strchr(tmp_node->content, '\t'))
			arr[i] = replace_tabs(tmp_node->content);
		else
			arr[i] = ft_strdup(tmp_node->content);
		i++;
	}
	ft_free_list(&settings->tmp_map);
}

void	validate_map(t_scene *settings)
{
	if (!settings->valid)
		return ;
	linked_to_array(settings);
	verify_position(settings);
	verify_walls(settings);
}
