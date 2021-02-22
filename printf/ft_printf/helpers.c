/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:57:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/22 18:36:28 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	update_content(char *new_str, t_node *node)
{
	char 	*padding;
	int		i;
	int		padding_length;

	i = 0;
	padding_length = node->pad_len - ft_strlen(new_str);
	while (i < padding_length)
		i++;
	padding = malloc(sizeof(char) * i + 1);
	if (!padding)
		return ;
	if (node->pad_is_zero)
		ft_memset(padding, '0', i);
	else
		ft_memset(padding, ' ', i);
	padding[i] = '\0';
	if (node->left_align)
		node->content = ft_strjoin(new_str, padding);
	else
		node->content = ft_strjoin(padding, new_str);
	free(padding);
	free(new_str);
}

int		manage_node(char *s, char **to_print, va_list ap, int i)
{
	t_node node;
	char *new_str;

	node.i = i;
	node.has_pad = FALSE;
	node.pad_is_zero = FALSE;
	node.left_align = FALSE;
	node.pad_len = FALSE;
	node.from_arg = FALSE;
	node.done = FALSE;
	node.content = NULL;
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
