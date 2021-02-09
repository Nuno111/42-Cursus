#include "get_next_line.h"

size_t		ft_get_line_size(t_list *node)
{
	size_t length;
	size_t i;

	length = 0;
	while (node)
	{
		i = 0;
		while (node->content[i] != '\n' && node->content[i])
		{
			length++;
			i++;
		}
		node = node->next;
	}
	return (length);
}

char		*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == c)
		return (&((char *)s)[i]);
	return (NULL);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	length;
	size_t src_length;

	src_length = 0;
	while (src[src_length])
		src_length++;
	length = 0;
	while (dst[length] && length < size)
		length += 1;
	i = length;
	while (src[length - i] && length + 1 < size && src[length - i] != '\n')
	{
		dst[length] = src[length - i];
		length += 1;
	}
	if (i < size)
		dst[length] = '\0';
	return (i + src_length);
}

int		ft_helper(char **line, t_list *node, t_list **head)
{
	t_list *tmp;

	*line = malloc(sizeof(char) * ft_get_line_size(node));
	if (!*line)
		return (err);
	while (node)
	{
		ft_strlcat(*line, node->content, BUFFER_SIZE);
		node = node->next;
	}
	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->content);
		free(tmp);
	}
	return (ok);
}

t_list		*ft_lstnew(t_list **list, int fd, char *eofile)
{
	t_list *new_node;
	t_list *tmp;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = malloc(sizeof(char) * BUFFER_SIZE);
	if (!new_node->content)
		return (NULL);
	if (read(fd, new_node->content, BUFFER_SIZE) != BUFFER_SIZE)
		*eofile = 'y';
	if (*list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	else
		*list = new_node;
	return (new_node);
}
