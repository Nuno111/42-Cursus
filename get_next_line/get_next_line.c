/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:44:27 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/11 13:15:12 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		read_file(int fd, char **fd_num, char *eofile)
{
	char buffer[BUFFER_SIZE + 1];
	ssize_t read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes == 0)
	{
		*eofile = 'y';
		return (eof);
	}
	else if (read_bytes < 0)
		return (err);
	if (fd_num[fd] == NULL)
		fd_num[fd] = ft_strdup(buffer);
	else
		fd_num[fd] = ft_strjoin(fd_num[fd], buffer);
	if (fd_num[fd] == NULL)
		return (err);
	return (ok);
}

int		update_line(int fd, char **fd_num, char **line)
{
	size_t i;
	char	*index;
	char	*tmp;

	i = 0;
	while (fd_num[fd][i] != '\n' && fd_num[fd])
		i++;
	index = ft_strchr(fd_num[fd], '\n');
	if (index)
	{
		*line = ft_substr(fd_num[fd], 0, index - fd_num[fd]);
		tmp = ft_substr(index, 0, ft_strlen(fd_num[fd]) -(index - fd_num[fd]));
		free(fd_num[fd]);
		fd_num[fd] = tmp;
		return (ok);
	}
	return (eof);
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
	while (!ft_strchr(fd_num[fd], '\n'))
		status = read_file(fd, fd_num, &eofile);
	if (status == err)
		return (err);
	if (eofile == 'y')
	{
		free(fd_num[fd]);
		return (eof);
	}
	else
		status = update_line(fd, fd_num, line);
	return (status);
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
