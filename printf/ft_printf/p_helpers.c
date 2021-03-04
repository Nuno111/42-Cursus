/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 22:10:54 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/04 20:44:45 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	void	add_letter(t_node *n, char c)
{
	char *new;

	new = malloc(sizeof(char) * 2);
	if (!new)
		return ;
	new[0] = c;
	new[1] = '\0';
	if (n->new == NULL)
		n->new = new;
	else
		n->new = str_join_free(&n->new, &new);
}

void	handle_hex(t_node *n, __int128 nbr)
{
	char *hex;

	hex = "0123456789abcdef";
	if (nbr >= 16)
	{
		handle_hex(n, nbr / 16);
		handle_hex(n, nbr % 16);
	}
	else
		add_letter(n, hex[nbr]);
}

void	handle_p(t_node *n)
{
	__int128 nbr;
	char *filler;

	nbr = va_arg(n->ap, __int128);
	if (nbr == 0 || nbr <= T_MIN_LONG)
		n->new = ft_strdup("(nil)");
	else
	{
		if (nbr < 0)
			nbr *= -1;
		add_letter(n, '0');
		add_letter(n, 'x');
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
