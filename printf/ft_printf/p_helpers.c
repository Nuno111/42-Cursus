/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 22:10:54 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/05 15:51:32 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	void	handle_hex(t_node *n, unsigned long nbr)
{
	char *hex;

	hex = "0123456789abcdef";
	if (nbr >= 16)
	{
		handle_hex(n, nbr / 16);
		handle_hex(n, nbr % 16);
	}
	else
		add_letter(hex[nbr], &n->new);
}

void	handle_p(t_node *n)
{
	unsigned long nbr;
	char *filler;

	nbr = va_arg(n->ap, unsigned long);
	if (nbr == 0)
		n->new = ft_strdup("(nil)");
	else
	{
		add_letter('0', &n->new);
		add_letter('x', &n->new);
		handle_hex(n, nbr);
	}
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
