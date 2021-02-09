#include "get_next_line.h"

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
	return (i + ft_strlen(src));
}

void		ft_helper(char **line, t_list *node, t_list **head)
{
	t_list *tmp;

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
}

t_list		*ft_lstnew(t_list **list, int fd, char *eofile)
{
	t_list *new;
	t_list *tmp;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = malloc(sizeof(char) * BUFFER_SIZE);
	if (!new->content)
		return (NULL);
	new->bytes_read = read(fd, new->content, BUFFER_SIZE);
	if (new->bytes_read != BUFFER_SIZE)
		*eofile == 'y';
	if (*list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*list = new;
	return (new);
}
