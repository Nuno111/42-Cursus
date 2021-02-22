/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:28:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/22 15:38:04 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_zero(char *s, t_node *node)
{
	if (s[node->i - 1] == '-')
		node->has_pad = TRUE;
	else
	{
		node->has_pad = TRUE;
		node->pad_is_zero = TRUE;
		node->left_align = FALSE;
	}
	node->i++;
}

void	handle_asterisk(t_node *node)
{
		node->has_pad = TRUE;
		node->from_arg = TRUE;
		node->i++;
}

void	handle_dot(t_node *node)
{
	node->pad_is_zero = TRUE;
	node->has_pad = TRUE;
	node->can_trunc = 1;
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

