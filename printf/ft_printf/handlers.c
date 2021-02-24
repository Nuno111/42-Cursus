/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:29:09 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/24 23:36:30 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_types(char *s, t_node *node, va_list ap)
{
	if (!s[node->i])
		return ;
	if (s[node->i] == 'd')
		handle_d(node, ap);
}

void	handle_cases(char *s, t_node *node, va_list ap)
{
	if (!s[node->i])
		return ;
	if (s[node->i] == '-')
		handle_hyphen(node);
	else if (s[node->i] == '0')
		handle_zero(node);
	else if (s[node->i] == '*')
		handle_asterisk(s, node, ap);
	else if (s[node->i] == '.')
		handle_dot(node);
	else if (ft_isdigit(s[node->i])  && !node->has_prec)
		update_padding(s, node, ap, &node->width_len, FALSE);
	else if (ft_isdigit(s[node->i]) && node->has_prec)
		update_padding(s, node, ap, &node->prec_len, FALSE);
	else
		handle_types(s, node, ap);
	// need to check another ignored case if 0 is present and has precision
}
