/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:23:12 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/05 15:33:37 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static	char	*str_join_char(char c, char *filler, t_node *n)
{
	char *new;
	size_t len;

	len = ft_strlen(filler);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	if (n->left_align)
	{
		new[0] = c;
		ft_memmove(&new[1], filler, len);
	}
	else
	{
		ft_memmove(new, filler, len);
		new[len] = c;
	}
	return (new);
}

static	void	handle_width_c(char c, t_node *n)
{
	char	*filler;

	filler = get_filler(" ", n->width_len, n->pad_is_zero);
	n->buf = str_join_char(c, filler, n);
	n->buf_len += ft_strlen(filler) + 1;
	free(filler);
}

void		handle_c(t_node *n)
{
	char	arg;

	n->type = 'c';
	arg = va_arg(n->ap, int);

	if (n->width_len > 1)
		handle_width_c(arg, n);
	else
	{
		n->buf = ft_strdup(&arg);
		n->buf_len++;
	}
	n->i++;
	n->done = 1;
}
