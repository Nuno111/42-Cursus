/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:15:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/02 01:16:44 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	init(t_node *n)
{
	n->s = NULL;
	n->buf = NULL;
	n->new = NULL;
	->type = NULL;
	n->buf_len = 0;
	n->i = 0;
	n->len = 0;
	n->prec_len = 0;
	n->width_len = 0;
	n->left_align = false;
	n->has_prec = false;
	n->has_width = false;
	n->from_arg = false;
	n->pad_is_zero = false;
	n->done = false;
	n->can_trunc = false;
	n->is_neg = false;
	n->status = 0;
}

static	void	add_letter(t_node *n)
{
	char *new;

	new = malloc(sizeof(char) * 2);
	if (!new)
		return ;
	new[0] = n->s[n->i];
	new[1] = '\0';
	if (*n->buf == NULL)
		*n->buf = new;
	else
		*n->buf = str_join_free(n->buf, &new);
}

static	void	iterate_string(t_node *n)
{
	while (n->s[n->i])
	{
		if (n->s[n->i] != '%')
		{
			add_letter(n);
			n->i++;
		}
		else if (n->s[n->i] == '%' && n->s[n->i + 1] == '%')
		{
			n->i += 2;
			add_letter(n);
		}
		else
		{
			if (n->buf)
			{
				print_buffer(n, false);
				n->len += ft_strlen(n->buf);
				free(n->buf);
				n->buf = NULL;
			}
			new_buffer(n);
		}
	}
}

int				ft_printf(const char *s, ...)
{
	t_node *n;

	va_start(n->ap, s);
	init(n);
	va_end(n->ap);
	return (n->len);
}
