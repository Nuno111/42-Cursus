/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:29:09 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/02 00:14:04 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_types(t_node *n)
{
	char c;

	c = n->s[n->i];
	if (c == 'd')
		handle_d(n);
	else if (n == 'c')
		handle_c(n);
}

void	handle_cases(t_node *n)
{
	char c;

	c = n->s[n->i];
	if (c == '-')
		handle_hyphen(n);
	else if (c == '0')
		handle_zero(n);
	else if (c == '*')
		handle_asterisk(n);
	else if (c == '.')
		handle_dot(n);
	else if (ft_isdigit(c)  && !n->has_prec)
		update_padding(n);
	else if (ft_isdigit(c) && n->has_prec)
		update_padding(n);
	else
		handle_types(n);
}

void	new_buffer(t_node *n)
{
	handle_cases(n);
}
