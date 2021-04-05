/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 22:15:53 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/05 15:29:17 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_width(t_node *n)
{
	char	*filler;

	filler = get_filler(n->new, n->width_len, n->pad_is_zero);
	if (n->left_align)
		n->new = str_join_free(&n->new, &filler);
	else
		n->new = str_join_free(&filler, &n->new);
}

void	handle_precision(t_node *n)
{
	char	*filler;

	filler = get_filler(n->new, n->prec_len, true);
	n->new = str_join_free(&filler, &n->new);
}

void	update_content(t_node *n)
{
	if ((long)ft_strlen(n->new) < n->prec_len)
		handle_precision(n);
	if ((long)ft_strlen(n->new) < n->width_len)
		handle_width(n);
	n->buf = n->new;
}

void	reset_and_free(t_node *n)
{
	if (n->buf)
	{
		free(n->buf);
		n->buf = NULL;
	}
	n->new = NULL;
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
	n->is_neg = false;
}

void	handle_negative_wp(long *w_or_p_len, t_node *n)
{
	if (!n->has_prec)
	{
		n->left_align = true;
		n->hyphen = true;
		*w_or_p_len *= -1;
		if (n->pad_is_zero)
			n->pad_is_zero = false;
	}
	else
	{
		n->has_prec = false;
		if (n->zero && !n->hyphen)
			n->pad_is_zero = true;
	}
}
