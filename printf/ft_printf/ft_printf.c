/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:15:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/02 03:03:23 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_and_free(t_node *n)
{

	print_buffer(n, false);
	n->len += ft_strlen(n->buf);
	free(n->buf);
	n->buf = NULL;
}

static	void	add_letter(t_node *n)
{
	char *new;

	new = malloc(sizeof(char) * 2);
	if (!new)
		return ;
	new[0] = n->s[n->i];
	new[1] = '\0';
	if (n->buf == NULL)
		n->buf = new;
	else
		n->buf = str_join_free(&n->buf, &new);
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
				print_and_free(n);
			n->i++;
			new_buffer(n);
		}
	}
	if (n->buf)
		print_and_free(n);
}

static	void	init(t_node *n, const char *s)
{
	n->s = s;
	n->buf = NULL;
	n->new = NULL;
	n->type = 0;
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
}

int				ft_printf(const char *s, ...)
{
	t_node n;

	init(&n, s);
	va_start(n.ap, s);
	iterate_string(&n);
	va_end(n.ap);
	return (n.len);
}
