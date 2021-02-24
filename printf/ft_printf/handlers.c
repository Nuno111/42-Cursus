/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:29:09 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/24 11:36:20 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_padding(char *s, t_node *node, va_list ap, int *w_or_p_len, bool from_arg)
{
	int i;
	char *str_len;

	if (!node->has_prec)
		node->has_width = TRUE;
	i = 0;
	if (from_arg)
		*w_or_p_len = va_arg(ap, int);
	else
	{
		i = 0;
		while (ft_isdigit(s[node->i + i]))
			i++;
		str_len = ft_substr(s, node->i, i);
		*w_or_p_len = ft_atoi(str_len);
		free(str_len);
		// need to add on types, if pane_len > 0 then node->has_pad = TRUE
		// depending on type
		node->i++;
	}
	if (*w_or_p_len < 0)
	{
		if (!node->has_prec)
		{
			node->left_align = TRUE;
			*w_or_p_len *= -1;
		}
		else
		{
			node->has_prec = FALSE;
			*w_or_p_len = 0;
		}
	}
}

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
		handle_padding(s, node, ap, &node->width_len, FALSE);
	else if (ft_isdigit(s[node->i]) && node->has_prec)
		handle_padding(s, node, ap, &node->prec_len, FALSE);
	else
		handle_types(s, node, ap);
	// need to check another ignored case if 0 is present and has precision
}
