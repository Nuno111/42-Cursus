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

char	*ft_strcat(char *dest, char *src)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && src[j] != '\n')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_helper(char **line, t_list *node, t_list **head)
{
	t_list *tmp;

	*line = ft_calloc(ft_get_line_size(node), sizeof(char));
	if (!*line)
		return (err);
	while (node)
	{
		ft_strcat(*line, node->content);
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

	new_node = ft_calloc(1, sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = ft_calloc(BUFFER_SIZE, sizeof(char));
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
