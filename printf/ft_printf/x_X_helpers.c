/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_X_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:00:21 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/05 16:18:31 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_x_X(t_node *n, char type)
{
	unsigned int	arg;

	n->type = type;
	arg = va_arg(n->ap, unsigned int);
	handle_hex(n, arg);
	if (*n->new == '0' && n->width_len > 0 && !n->prec_len)
	{
		n->buf = get_filler("", n->width_len, n->pad_is_zero);
		free(n->new);
	}
	else if (*n->new == '0' && n->has_prec && !n->prec_len && !n->width_len)
		free(n->new);
	else
		update_content(n);
	n->i++;
	n->done = 1;
}
