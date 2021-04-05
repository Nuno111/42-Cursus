/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_X_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:00:21 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/25 15:44:13 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norm_again(t_node *n)
{
	if (n->left_align && !n->has_prec)
	{
		n->buf = get_filler("", n->width_len - 1, n->pad_is_zero);
		n->buf = str_join_free(&n->new, &n->buf);
	}
	else if (!n->has_prec)
	{
		n->buf = get_filler("", n->width_len - 1, n->pad_is_zero);
		n->buf = str_join_free(&n->buf, &n->new);
	}
	else
	{
		n->buf = get_filler("", n->width_len, n->pad_is_zero);
		free(n->new);
	}
}

void	handle_x_x(t_node *n, char type)
{
	unsigned int	arg;

	n->type = type;
	arg = va_arg(n->ap, unsigned int);
	handle_hex(n, arg);
	if (*n->new == '0' && n->width_len > 0 && !n->prec_len)
		norm_again(n);
	else if (*n->new == '0' && n->has_prec && !n->prec_len && !n->width_len)
		free(n->new);
	else
		update_content(n);
	n->i++;
	n->done = 1;
}
