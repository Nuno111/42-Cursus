/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:44:27 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/09 18:14:27 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char newline_found;
	char eofile;
	t_list *list;
	t_list *curr_node;

	list = NULL;
	newline_found = 'n';
	if (!fd || !line)
		return (err);
	while (newline_found == 'n')
	{
		curr_node = ft_lstnew(&list, fd, &eofile);
		if (!curr_node)
			return (err);
		if (eofile == 'y')
			return (eof);
		if (ft_strchr(curr_node->content, 10))
			newline_found = 'y';
	}
	return (ft_helper(line, list, &list));
}

int main()
{
	int		fd;
	int		j;
	char	*line = 0;

	j = 1;
	if (!(fd = open("test.txt", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
		j++;
	}
}
