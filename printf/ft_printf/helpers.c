/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:57:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/24 21:41:53 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*get_filler(char *new_str, t_node *node, int *len)
{
	char	*filler;
	int		new_len;

	new_len = *len - ft_strlen(new_str);
	filler = malloc(sizeof(char) * new_len + 1);
	if (!filler)
		return (NULL);
	if (node->pad_is_zero)
		ft_memset(filler, '0', new_len);
	else
		ft_memset(filler, ' ', new_len);
	filler[new_len] = '\0';
	return (filler);
}

char	*truncate_str(char *new_str, t_node *node)
{
	char *new;

	new = ft_substr(new_str, 0, node->prec_len);
	free(new_str);
	return (new);
}

void	update_content(char *new_str, t_node *node)
{
	char	*filler;
	int		length;
	char	*tmp;
	int		*b;

	if (node->can_trunc && (int)ft_strlen(new_str) < node->prec_len)
		new_str = truncate_str(new_str, node);
	length = ft_strlen(new_str);
	if (node->prec_len > node->width_len)
	{
		b = &node->prec_len;
		node->pad_is_zero = TRUE;
	}
	else if (node->has_width)
		b = &node->width_len;
	filler = get_filler(new_str, node, b);
	if (length > *b)
		node->content = new_str;
	else if (node->left_align)
		node->content = ft_strjoin(new_str, filler);
	else if (node->is_neg)
	{
		tmp = ft_strjoin("-", filler);
		node->content = ft_strjoin(tmp, new_str);
		free(tmp);
	}
	free(filler);
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
