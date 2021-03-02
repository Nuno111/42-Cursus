/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:23:12 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/02 19:13:51 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static	void	handle_width(char *c, t_node *n)
{
	char	*filler;

	filler = get_filler(" ", n->width_len, n->pad_is_zero);
	if (n->left_align)
		n->buf = ft_strjoin(c, filler);
	else
		n->buf = ft_strjoin(filler, c);
	n->buf_len += ft_strlen(filler) + 1;
	free(filler);
}

void		handle_c(t_node *n)
{
	char	arg;

	arg = va_arg(n->ap, int);

	if (n->width_len > 1)
		handle_width(&arg, n);
	else
	{
		n->buf = ft_strdup(&arg);
		n->buf_len++;
	}
	n->i++;
	n->done = 1;
}
