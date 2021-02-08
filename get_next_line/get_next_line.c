/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:44:27 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/08 00:37:14 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char newline_found;
	char eof;
	t_list *list;
	t_list *curr_node;

	newline_found = 'n';
	if (!fd || !line)
		return (ERR);
	while (!newline_found)
	{
		curr_node = ft_lstnew(&list, fd, &eof);
		if (!curr_node)
			return (ERR);
		if (eof == 'y')
			return (EOF);
		if (ft_strchr(curr_node, 10))
			newline_found = 'y';
	}
	//ft_transfer_data(line, list);
	//ft_lstclear(&list)
	return (OK);
}
