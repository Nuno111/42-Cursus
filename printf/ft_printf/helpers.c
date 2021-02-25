/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:57:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/25 01:41:19 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

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


void	update_padding(char *s, t_node *node, va_list ap, int *w_or_p_len, bool from_arg)
{
	int i;
	char *str_len;

	if (!node->has_prec)
		node->has_width = TRUE;
	i = 0;
	if (from_arg)
		*w_or_p_len = va_arg(ap, int);
	else
	{
		i = 0;
		while (ft_isdigit(s[node->i + i]))
			i++;
		str_len = ft_substr(s, node->i, i);
		*w_or_p_len = ft_atoi(str_len);
		free(str_len);
		node->i += i;
	}
	if (*w_or_p_len < 0)
	{
		if (!node->has_prec)
		{
			node->left_align = TRUE;
			*w_or_p_len *= -1;
		}
		else
		{
			node->has_prec = FALSE;
			*w_or_p_len = 0;
		}
	}
}
