/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:44:27 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/12 12:33:27 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t i;
	size_t length;

	if (!src)
		return (0);
	length = ft_strlen(src);
	if (!dst || !size)
		return (length);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (length);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		read_file(int fd, char **fd_num, char *buffer)
{
	ssize_t read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	if (read_bytes == 0)
	{
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
	char	*index;
	char	*tmp;

	index = ft_strchr(fd_num[fd], '\n');
	if (index)
	{
		*line = ft_substr(fd_num[fd], 0, index - fd_num[fd]);
		tmp = ft_substr(index, 1, ft_strlen(fd_num[fd]) - (index - fd_num[fd] + 1));
		free(fd_num[fd]);
		fd_num[fd] = tmp;
		return (ok);
	}
	else
	{
		if (fd_num[fd])
		{
			*line = ft_strdup(fd_num[fd]);
			free(fd_num[fd]);
		}
		else
			*line = ft_strdup("\0");
	}
	return (eof);
}

int		get_next_line(int fd, char **line)
{
	static char	*fd_num[MAX_FD];
	int			status;
	char *buffer;

	status = 1;
	if (line == NULL || BUFFER_SIZE <= 0 ||  fd < 0 || fd >= MAX_FD)
		return (-1);
	while (!ft_strchr(fd_num[fd], '\n') && status > 0)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		status = read_file(fd, fd_num, buffer);
		free(buffer);
	}
	if (status == err)
		return (err);
	else
		status = update_line(fd, fd_num, line);
	return (status);
}

/*
int main()
{
	int		fd;
	int		j;
	char	*line = 0;

	j = 1;
	if (!(fd = open("1.txt", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
		j++;
	}
}
*/

