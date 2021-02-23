/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:28:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/23 22:34:12 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hyphen(t_node *node)
{
		node->left_align = TRUE;
		node->i++;
}

void	handle_zero(t_node *node)
{
	if (node->left_align)
		node->has_width = TRUE;
	else if (node->has_prec)
		node->pad_is_zero = TRUE;
	else
	{
		node->has_width = TRUE;
		node->pad_is_zero = TRUE;
	}
	node->i++;
}

void	handle_asterisk(char *s, t_node *node, va_list ap)
{
		if (!(node->has_prec))
		{
			node->has_width = TRUE;
			handle_padding(s, node, ap, &node->width_len, TRUE)
		}
		else
			handle_padding(s, node, ap, &node->prec_len, TRUE);
		node->i++;
}

void	handle_dot(t_node *node)
{
	node->has_prec = TRUE;
	node->i++;
}

int		handle_percent(char *s, char **to_print, va_list ap, int index)
{
	if (s[index + 1] == '%')
	{
		add_letter(s[index], to_print);
		return (index += 2);
	}
	else if (s[index + 1])
		index = manage_node(s, to_print, ap, ++index);
	return (++index);
}

