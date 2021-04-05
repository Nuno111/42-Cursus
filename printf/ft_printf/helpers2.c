/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:17:47 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/05 17:53:59 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_types(t_node *n)
{
	char	c;

	c = n->s[n->i];
	if (c == 'd' || c == 'i')
		handle_d(n);
	if (c == 'c')
		handle_c(n);
	if (c == 's')
		handle_s(n);
	if (c == 'p')
		handle_p(n);
	if (c == 'u')
		handle_u(n);
	if (c == 'x' || c == 'X')
		handle_x_x(n, c);
}

void	handle_cases(t_node *n)
{
	char	c;

	c = n->s[n->i];
	if (c == '-')
		handle_hyphen(n);
	else if (c == '0')
		handle_zero(n);
	else if (c == '*')
		handle_asterisk(n);
	else if (c == '.')
		handle_dot(n);
	else if (ft_isdigit(c) && !n->has_prec)
		update_padding(n, &n->width_len, false);
	else if (ft_isdigit(c) && n->has_prec)
		update_padding(n, &n->prec_len, false);
	else
		handle_types(n);
}

void	handle_hex(t_node *n, unsigned long nbr)
{
	char	*hex;

	if (n->type == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nbr >= 16)
	{
		handle_hex(n, nbr / 16);
		handle_hex(n, nbr % 16);
	}
	else
		add_letter(hex[nbr], &n->new);
}

void	add_letter(char c, char **buffer)
{
	char	*new;

	new = malloc(sizeof(char) * 2);
	if (!new)
		return ;
	new[0] = c;
	new[1] = '\0';
	if (*buffer == NULL)
		*buffer = new;
	else
		*buffer = str_join_free(buffer, &new);
}
