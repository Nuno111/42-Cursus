/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 22:15:53 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/02 19:18:43 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_and_free(t_node *n)
{
	if (n->buf)
	{
		free(n->buf);
		n->buf = NULL;
	}
	n->buf_len = 0;
	n->type = 0;
	n->prec_len = 0;
	n->width_len = 0;
	n->left_align = false;
	n->has_prec = false;
	n->has_width = false;
	n->from_arg = false;
	n->pad_is_zero = false;
	n->done = false;
	n->can_trunc = false;
	n->is_neg = false;
}

void	handle_negative_wp(long *w_or_p_len, t_node *n)
{
	if (!n->has_prec)
	{
		n->left_align = true;
		*w_or_p_len *= -1;
		if (n->pad_is_zero)
			n->pad_is_zero = false;
	}
	else
	{
		n->has_prec = false;
		*w_or_p_len = 0;
	}
}
