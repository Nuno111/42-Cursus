/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:44:27 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/07 17:26:20 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	size_t bytes_read;
	char newline_found;
	char eof_reached;
	t_list *list;

	newline_found = 'n';
	if (!fd || !line)
		return (-1);
	while (!newline_found)
	{
		if(!(list->content = malloc(sizeof(char) * BUFFER_SIZE)))
			return(-1);
		list->bytes_read = read(fd, list->content, BUFFER_SIZE);
	}
	if (newline_found)
		return (1);
	else if (eof_reached)
		return (0);
	else
		return (-1);

}
