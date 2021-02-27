/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:28:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/27 13:58:08 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hyphen(t_node *node)
{
		node->left_align = true;
		node->i++;
}

void	handle_zero(t_node *node)
{
	if (node->left_align)
		node->has_width = true;
	else if (node->has_prec)
		node->pad_is_zero = true;
	else
	{
		node->has_width = true;
		node->pad_is_zero = true;
	}
	node->i++;
}

void	handle_asterisk(char *s, t_node *node, va_list ap)
{
		if (!(node->has_prec))
			update_padding(s, node, ap, &node->width_len, true);
		else
			update_padding(s, node, ap, &node->prec_len, true);
		node->i++;
}

void	handle_dot(t_node *node)
{
	node->has_prec = true;
	node->pad_is_zero = true;
	node->i++;
}
