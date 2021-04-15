/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:25:30 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/14 23:05:12 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*replace_tabs(char *str)
{
	size_t	i;
	char	*new;
	char	*tmp;

	new = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\t')
			ft_add_letter(str[i], &new, false);
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

void	verify_position(t_scene *settings)
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
				error_and_exit_settings(settings, "Error\nOnly one starting postion must be given.");
			j++;
		}
		i++;
	}
	if (!position_found)
		error_and_exit_settings(settings, "Error\nNo player starting position has been given");
}

void	verify_walls(t_scene *settings, char **m)
{
	size_t i;
	size_t j;
	char *valid;
	char	*charset;

	charset = "NESW02";
	valid = "1+ ";
	i = 1;
	while (i < settings->map_size)
	{
		j = 1;
		while (j < settings->map_width - 1)
		{
			if (m[i][j] == ' ')
			{
				if (!ft_strchr(valid, m[i - 1][j - 1])
				|| !ft_strchr(valid, m[i - 1][j])
				|| !ft_strchr(valid, m[i - 1][j + 1])
				|| !ft_strchr(valid, m[i][j - 1])
				|| !ft_strchr(valid, m[i][j + 1])
				|| !ft_strchr(valid, m[i + 1][j - 1])
				|| !ft_strchr(valid, m[i + 1][j])
				|| !ft_strchr(valid, m[i + 1][j + 1])
				)
					error_and_exit_settings(settings, "Error\nMap is not properly surrounded by walls.");
			}
			if (ft_strchr(charset, m[i][j]))
			{
				if (m[i - 1][j - 1] == '+'
				|| m[i - 1][j] == '+'
				|| m[i - 1][j + 1] == '+'
				|| m[i][j - 1] == '+'
				|| m[i][j + 1] == '+'
				|| m[i + 1][j - 1] == '+'
				|| m[i + 1][j] == '+'
				|| m[i + 1][j + 1] == '+'
				)
					error_and_exit_settings(settings, "Error\nMap is not properly surrounded by walls.");
			}
			j++;
		}
		i++;
	}
}

char	**linked_to_array(t_scene *settings, t_list *head)
{
	int		size;
	char	**arr;
	int		i;
	t_list	*tmp_node;

	i = 0;
	size = ft_lstsize(head);
	if (size <= 0)
		error_and_exit_settings(settings, "Error\nScene description incomplete, RTFM.");
	arr = malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	while (head)
	{
		tmp_node = head;
		head = head->next;
		if (ft_strchr(tmp_node->content, '\t'))
			arr[i] = replace_tabs(tmp_node->content);
		else
			arr[i] = ft_strdup(tmp_node->content);
		i++;
	}
	arr[i] = NULL;
	return(arr);
}
