/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:44:27 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/11 00:19:26 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		eol_exists(int fd, char *fd_num, char *eofile)
{
	char buffer[BUFFER_SIZE + 1];
	ssize_t read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes == 0)
	{
		*eofile == 'y';
		return (0);
	}
	else if (read_bytes < 0)
		return (err);
	buffer[read_bytes] = '\0';
	if (fd_num[fd] == NULL)
		fd_num[fd] = ft_strdup(buffer);
	else
		fd_num[fd] = ft_strjoin(&fd_num[fd], buffer);
	if (ft_strchr(fd_num[fd], '\n'))
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*fd_num[MAX_FD];
	char		eofile;
	int			status;

	status = 1;
	eofile = 'n';
	if (line == NULL || BUFFER_SIZE <= 0 ||  fd < 0 || fd >= MAX_FD)
		return (-1);
	while (status > 0)
		status = eol_exists(fd, fd_num, &eofile);
	if (status == err)
		return (err);
	if (eofile == 'y')
	{
		free(fd_num[fd]);
		return (eof);
	}
	else
		update_line();
	return (ok);
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
