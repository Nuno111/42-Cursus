/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:28:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/05 17:42:32 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hyphen(t_node *n)
{
	n->left_align = true;
	n->i++;
	if (n->pad_is_zero)
		n->pad_is_zero = false;
}

void	handle_zero(t_node *n)
{
	if (n->left_align)
		n->has_width = true;
	else if (n->has_prec && n->has_width)
		n->pad_is_zero = false;
	else if (n->has_prec)
		n->pad_is_zero = true;
	else
	{
		n->has_width = true;
		n->pad_is_zero = true;
	}
	n->i++;
}

void	handle_asterisk(t_node *n)
{
	if (!(n->has_prec))
		update_padding(n, &n->width_len, true);
	else
		update_padding(n, &n->prec_len, true);
	n->i++;
}

void	handle_dot(t_node *n)
{
	n->has_prec = true;
	if (n->pad_is_zero)
		n->pad_is_zero = false;
	n->i++;
}
