/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:37:36 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/05 16:14:02 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_s(t_node *n)
{
	char *filler;
	char *new;
	char *arg;

	arg = va_arg(n->ap, char*);
	if (arg == NULL)
		new = ft_strdup("(null)");
	else
		new = ft_strdup(arg);
	if (n->prec_len < (long)ft_strlen(new) && n->has_prec)
		new = truncate_str(new, n);
	if (n->width_len > (long)ft_strlen(new))
	{
		filler = get_filler(new, n->width_len, n->pad_is_zero);
		if (n->left_align)
			n->buf = str_join_free(&new, &filler);
		else
			n->buf = str_join_free(&filler, &new);
	}
	else
		n->buf = new;
	n->i++;
	n->done = 1;
}
