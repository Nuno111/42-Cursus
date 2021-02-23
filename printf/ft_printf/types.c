/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:57:03 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/23 23:23:15 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_d(char *s, t_node *node, va_list ap)
{
	char *new_str;

	new_str = NULL;
	if (node->has_prec)
		node->pad_is_zero = TRUE;
	new_str = ft_itoa(va_arg(ap, int));
	if (new_str == '0' && node->width_len > 0)
		node->content = get_width(new_str, node);
	else if (new_str != '0')
		update_content(new_str, node);
	else
		node->content = new_str;
	node->done = 1;
}

