/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:44:27 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/08 18:25:45 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_list **lst)
{
	t_list *tmp;

	if (*lst)
	{
		while (*lst != NULL)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			free(tmp->content);
			free(tmp);
		}
		lst = NULL;
	}
}

int get_next_line(int fd, char **line)
{
	char newline_found;
	char eofile;
	t_list *list;
	t_list *curr_node;

	newline_found = 'n';
	if (!fd || !line)
		return (err);
	while (!newline_found)
	{
		curr_node = ft_lstnew(&list, fd, &eofile);
		if (!curr_node)
			return (err);
		if (eof == 'y')
			return (eof);
		if (ft_strchr(curr_node->content, 10))
			newline_found = 'y';
	}
	ft_transfer_data(line, list);
	ft_lstclear(&list);
	return (ok);
}
