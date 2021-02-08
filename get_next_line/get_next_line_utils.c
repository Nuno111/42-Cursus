#include "get_next_line.h"

t_list	*ft_lstnew(t_list **list, int fd, char *eofile)
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

char	*ft_strchr(const char *s, int c)
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
