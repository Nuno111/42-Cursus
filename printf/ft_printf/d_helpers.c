/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 01:40:04 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/05 17:28:44 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	add_minus(t_node *n)
{
	char	*tmp;

	tmp = ft_strjoin("-", n->new);
	free(n->new);
	n->new = tmp;
}

static	void	handle_precision_d(t_node *n, bool *prec_handled)
{
	char	*filler;

	filler = get_filler(n->new, n->prec_len, true);
	n->new = str_join_free(&filler, &n->new);
	if (n->is_neg)
		add_minus(n);
	*prec_handled = true;
}

static	void	handle_width_d(t_node *n, bool prec_handled)
{
	char	*filler;

	if (n->is_neg && !prec_handled)
		n->width_len--;
	filler = get_filler(n->new, n->width_len, n->pad_is_zero);
	if (n->is_neg && !prec_handled && !n->pad_is_zero)
		add_minus(n);
	if (n->left_align)
		n->new = str_join_free(&n->new, &filler);
	else
	{
		n->new = str_join_free(&filler, &n->new);
		if (n->is_neg && !prec_handled && !ft_strchr(n->new, '-'))
			add_minus(n);
	}
}

static	void	update_content_d(t_node *n)
{
	bool	precision_handled;

	precision_handled = false;
	if ((long)ft_strlen(n->new) < n->prec_len)
		handle_precision_d(n, &precision_handled);
	if ((long)ft_strlen(n->new) < n->width_len)
		handle_width_d(n, precision_handled);
	if (n->is_neg && !(ft_strchr(n->new, '-')))
		add_minus(n);
	n->buf = n->new;
}

void	handle_d(t_node *n)
{
	long	arg;

	arg = (long)va_arg(n->ap, int);
	if (arg < 0)
	{
		n->is_neg = true;
		arg *= -1;
	}
	n->new = ft_itoa(arg);
	if (*n->new == '0' && n->width_len > 0 && !n->prec_len)
		norm_again(n);
	else if (*n->new == '0' && n->has_prec && !n->prec_len && !n->width_len)
		free(n->new);
	else
		update_content_d(n);
	n->i++;
	n->done = 1;
}
