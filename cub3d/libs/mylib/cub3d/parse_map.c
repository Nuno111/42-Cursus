/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:25:30 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/13 23:32:45 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	char	*replace_tabs(t_scene *settings)
{

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
	replace_tabs(settings);
	linked_to_array(settings);
}
