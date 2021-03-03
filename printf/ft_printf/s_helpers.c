/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:37:36 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/03 16:19:32 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_s(t_node *n)
{
	char *tmp;
	char *filler;

	tmp = va_arg(n->ap, char*);

	if (n->width_len > ft_strlen(tmp))
		filler = get_filler(tmp, n->width_len, n->pad_is_zero);
	if (filler)
	{
		if (n->left_align)
			n->buf = str_join_free(&tmp, &filler);
		else
			n->buf = str_join_free(&filler, &tmp);
	}
	else
	{
		n->buf = tmp;
		free(filler);
	}
	n->i++;
	n->done = 1;
}
