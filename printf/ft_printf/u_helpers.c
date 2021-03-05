/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:39:48 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/05 13:51:53 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	handle_precision(t_node *n)
{
	char	*filler;

	filler = get_filler(n->new, n->prec_len, true);
	n->new = str_join_free(&filler, &n->new);
}

static	void	handle_width(t_node *n)
{
	char	*filler;

	filler = get_filler(n->new, n->width_len, n->pad_is_zero);
	if (n->left_align)
		n->new = str_join_free(&n->new, &filler);
	else
		n->new = str_join_free(&filler, &n->new);
}

static	void	update_content_d(t_node *n)
{
	if ((long)ft_strlen(n->new) < n->prec_len)
		handle_precision(n);
	if ((long)ft_strlen(n->new) < n->width_len)
		handle_width(n);
	n->buf = n->new;
}

void	handle_u(t_node *n)
{
	unsigned int	arg;

	arg = va_arg(n->ap, unsigned int);
	n->new = ft_itoa(arg);
	if (*n->new == '0' && n->width_len > 0 && !n->prec_len)
	{
		n->buf = get_filler("", n->width_len, n->pad_is_zero);
		free(n->new);
	}
	else if (*n->new == '0' && n->has_prec && !n->prec_len && !n->width_len)
		free(n->new);
	else
		update_content_d(n);
	n->i++;
	n->done = 1;
}
