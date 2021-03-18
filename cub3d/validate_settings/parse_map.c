/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:25:30 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/18 12:38:10 by ngregori         ###   ########.fr       */
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
				error_and_exit(settings, "Error: Only one starting postion must be given");
			j++;
		}
		i++;
	}
}

bool	verify_str(char *str, bool whole)
{
	if (whole)
	{
		while (*str && (*str == '1' || *str == ' '))
			str++;
		if (*str == '\0')
			return (true);
		return (false);
	}
	else
	{
		if (str[0] == '1' && str[ft_strlen(str) - 1] == '1')
			return (true);
		return (false);
	}
}

void	verify_walls(t_scene *settings)
{
	char	*str;
	size_t	i;
	size_t	arr_len;
	bool	str_is_valid;

	arr_len = 0;
	while (settings->map[arr_len])
		arr_len++;
	i = 0;
	while (settings->map[i])
	{
		str = ft_strtrim(settings->map[i], " ");
		if (i == 0 || i == arr_len)
			str_is_valid = verify_str(str, true);
		else
			str_is_valid = verify_str(str, false);
		if (!str_is_valid)
			error_and_exit(settings, "Error when reading map, map is not properly surrounded by walls");
		free(str);
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
		error_and_exit(settings, "Scene description incomplete. RTFM");
	arr = malloc(sizeof(char *) * size);
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
	return(arr);
}
