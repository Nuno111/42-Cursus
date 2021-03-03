/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:37:36 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/03 17:00:11 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_s(t_node *n)
{
	char *tmp;
	char *filler;

	tmp = va_arg(n->ap, char*);
	if (n->width_len > (long)ft_strlen(tmp))
	{
		filler = get_filler(tmp, n->width_len, n->pad_is_zero);
		if (n->left_align)
			n->buf = ft_strjoin(tmp, filler);
		else
			n->buf = ft_strjoin(filler, tmp);
		free(filler);
	}
	else
		n->buf = ft_strdup(tmp);
	n->i++;
	n->done = 1;
}
