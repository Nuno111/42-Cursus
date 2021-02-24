/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:57:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/24 01:02:21 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*get_width(char *new_str, t_node *node)
{
	char	*width;
	int		width_len;

	width_len = node->width_len - ft_strlen(new_str);
	width = malloc(sizeof(char) * width_len + 1);
	if (!width)
		return (NULL);
	if (node->pad_is_zero)
		ft_memset(width, '0', width_len);
	else
		ft_memset(width, ' ', width_len);
	width[width_len] = '\0';

	return (width);
}

char	*truncate_str(char *new_str, t_node *node)
{
	char *truncated;

	truncated = ft_substr(new_str, 0, node->prec_len);
	free(new_str);
	return (truncated);
}

void	update_content(char *new_str, t_node *node)
{
	char	*width;
	int		length;

	if (node->can_trunc)
		new_str = truncate_str(new_str, node);
	length = ft_strlen(new_str);
	if (node->has_width)
	{
		width = get_width(new_str, node);
		if (length > node->width_len)
			node->content = new_str;
		else if (node->left_align)
			node->content = ft_strjoin(new_str, width);
		else
			node->content = ft_strjoin(width, new_str);
		free(width);
	}
	else
		node->content = new_str;
	free(new_str);
}

int		manage_node(char *s, char **to_print, va_list ap, int i)
{
	t_node node;
	char *new_str;

	node.i = i;
	node.has_width = FALSE;
	node.has_prec = FALSE;
	node.pad_is_zero = FALSE;
	node.left_align = FALSE;
	node.from_arg = FALSE;
	node.done = FALSE;
	node.content = NULL;
	node.prec_len = 0;
	node.width_len = 0;
	while (node.done != TRUE)
		handle_cases(s, &node, ap);
	if (node.content)
	{
		new_str = ft_strjoin(*to_print, node.content);
		free(node.content);
		if (*to_print)
			free(*to_print);
		*to_print = new_str;
	}
	return (node.i);
}

int		iterate_string(char *s, char **to_print, va_list ap)
{
	int	i;
	int length;

	length = ft_strlen(s);
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			add_letter(s[i], to_print);
			i++;
		}
		else
			i = handle_percent(s, to_print, ap, i);
		if (i < 0)
			return (-1);
		else if (i > length)
			return (0);
	}
	return (0);
}

void	add_letter(char s, char **to_print)
{
	char *new;

	if (*to_print == NULL)
	{
		*to_print = ft_strdup("");
	}
	new = ft_strjoin_c(*to_print, s);
	free(*to_print);
	*to_print = new;
}
