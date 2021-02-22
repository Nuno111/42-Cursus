/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:29:09 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/22 17:52:45 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_padding(char *s, t_node *node, va_list ap)
{
	int		i;
	char	*str_len;

	if (node->from_arg)
		node->pad_len = va_arg(ap, int);
	else
	{
		i = 0;
		while (ft_isdigit(s[node->i + i]))
			i++;
		str_len = ft_substr(s, node->i, i);
		node->pad_len = ft_atoi(str_len);
		free(str_len);
		// need to add on types, if pane_len > 0 then node->has_pad = TRUE
		// depending on type
		node->i++;
		handle_types(s, node, ap);
	}
	node->done = 1;
}

void	handle_types(char *s, t_node *node, va_list ap)
{
	if (!s[node->i])
		return ;
	if (s[node->i] == 'd')
		handle_d(s, node, ap);
}

void	handle_cases(char *s, t_node *node, va_list ap)
{
	if (!s[node->i])
		return ;
	if (s[node->i] == '-')
	{
		node->left_align = TRUE;
		node->i++;
	}
	else if (s[node->i] == '0')
		handle_zero(s, node);
	else if (s[node->i] == '*')
		handle_asterisk(node);
	else if (s[node->i] == '.')
		handle_dot(node);
	else if (ft_isdigit(s[node->i]) && !node->from_arg)
		handle_padding(s, node, ap);
	else
		handle_types(s, node, ap);
	// need to check another ignored case if 0 is present and has precision
}
