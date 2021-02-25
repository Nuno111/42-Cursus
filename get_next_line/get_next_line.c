/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:44:27 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/25 14:19:25 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	length;

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

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			read_file(int fd, char **arr, char *buffer)
{
	ssize_t	read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
		return (ERR);
	if (read_bytes == 0)
		return (EOFILE);
	buffer[read_bytes] = '\0';
	if (arr[fd] == NULL)
		arr[fd] = ft_strdup(buffer);
	else
		arr[fd] = ft_strjoin(arr[fd], buffer);
	if (arr[fd] == NULL)
		return (ERR);
	return (OK);
}

int			update_line(int fd, char **arr, char **line)
{
	char	*index;
	char	*tmp;

	index = ft_strchr(arr[fd], '\n');
	if (index)
	{
		*line = ft_substr(arr[fd], 0, index - arr[fd]);
		tmp = ft_substr(index, 1, ft_strlen(arr[fd]) - (index - arr[fd] + 1));
		free(arr[fd]);
		arr[fd] = tmp;
		return (OK);
	}
	else
	{
		if (arr[fd])
		{
			*line = ft_strdup(arr[fd]);
			free(arr[fd]);
		}
		else
			*line = ft_strdup("\0");
	}
	return (EOFILE);
}

int			get_next_line(int fd, char **line)
{
	static char	*arr[MAX_FD];
	int			status;
	char		*buffer;

	status = 1;
	if (line == NULL || BUFFER_SIZE <= 0 || fd < 0 || fd >= MAX_FD)
		return (ERR);
	while (!ft_strchr(arr[fd], '\n') && status > 0)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (ERR);
		status = read_file(fd, arr, buffer);
		free(buffer);
	}
	if (status == ERR)
		return (ERR);
	else
		status = update_line(fd, arr, line);
	return (status);
}
