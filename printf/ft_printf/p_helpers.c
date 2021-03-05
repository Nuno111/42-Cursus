/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 22:10:54 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/05 19:39:43 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_p(t_node *n)
{
	unsigned long	nbr;
	char			*filler;

	nbr = va_arg(n->ap, unsigned long);
	add_letter('0', &n->new);
	add_letter('x', &n->new);
	handle_hex(n, nbr);
	if (n->width_len > (long)ft_strlen(n->new))
	{
		filler = get_filler(n->new, n->width_len, n->pad_is_zero);
		if (n->left_align)
			n->buf = str_join_free(&n->new, &filler);
		else
			n->buf = str_join_free(&filler, &n->new);
	}
	else
		n->buf = n->new;
	n->done = 1;
	n->i++;
}
