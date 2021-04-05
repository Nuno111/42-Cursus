/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:39:48 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/05 15:29:53 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_u(t_node *n)
{
	unsigned int	arg;

	arg = va_arg(n->ap, unsigned int);
	n->new = ft_itoa(arg);
	if (*n->new == '0' && n->width_len > 0 && !n->prec_len)
		norm_again(n);
	else if (*n->new == '0' && n->has_prec && !n->prec_len && !n->width_len)
		free(n->new);
	else
		update_content(n);
	n->i++;
	n->done = 1;
}
