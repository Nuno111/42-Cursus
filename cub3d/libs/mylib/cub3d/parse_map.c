/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:25:30 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/13 22:58:39 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	linked_to_array(t_scene *settings)
{
	int		size;
	char	**arr;
	int		i;
	t_list	tmp_node;

	size = ft_lstsize(settings->tmp_map);
	arr = malloc(sizeof(char *) * size);
	if (!arr)
		return 	;
	tmp_node = *(settings->tmp_map);
	while (tmp_node.content)
	{
		arr[i] = ft_strdup(tmp_node.content);
		tmp_node = *tmp_node.next;
		i++;
	}
	ft_free_list(&settings->tmp_map);
}

void	validate_map(t_scene *settings)
{
	if (!settings->valid)
		return ;
	linked_to_array(settings);

}
