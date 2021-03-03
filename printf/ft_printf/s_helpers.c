/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:37:36 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/03 17:09:26 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_s(t_node *n)
{
	char *tmp;
	char *filler;
	char *new;

	tmp = va_arg(n->ap, char*);
	if (n->prec_len < (long)ft_strlen(tmp) && n->has_prec)
		new = truncate_str(tmp, n);
	else
		new = ft_strdup(tmp);
	if (n->width_len > (long)ft_strlen(tmp))
	{
		filler = get_filler(tmp, n->width_len, n->pad_is_zero);
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
