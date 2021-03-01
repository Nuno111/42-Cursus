/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:15:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/01 23:30:43 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_letter(t_node *n)
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

void		iterate_string(t_node *n)
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
			handle_percent(n);
	}
}

int		ft_printf(const char *s, ...)
{
	t_node *n;

	va_start(n->ap, s);
	init(n);
	va_end(n->ap);
	return (n->status);
}

// Flags -0
// Width *
// precision .
// sizes

// Options
// Padding is only added if necessary, length argument < padding
// -0 or 0-	padding = spaces	aligned left, 0 is ignored
// * 		padding = spaces	determined by argument
// .*		padding = 0			determined by argument
// *.		padding = spaces	determined by argument
// . 		padding = spaces	determined by preceding number
// 0d 		padding = 0			determined by preceding number
