/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:57:03 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/22 18:36:48 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_d(char *s, t_node *node, va_list ap)
{
	char *new_str;

	if (node->pad_len > 0)
		node->has_pad = TRUE;
	if (node->from_arg)
		handle_padding(s, node, ap);
	new_str = ft_itoa(va_arg(ap, int));
	if (node->pad_len > (int)ft_strlen(new_str) && node->has_pad)
		update_content(new_str, node);
	else if (*new_str == '0')
		return ;
	else
		node->content = new_str;
	node->done = 1;
}

