/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:57:03 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/24 21:04:19 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_d(t_node *node, va_list ap)
{
	char	*new_str;
	int		arg;

	new_str = NULL;
	if (node->has_prec)
		node->can_trunc = TRUE;
	arg = va_arg(ap, int);
	if (arg < 0)
	{
		node->is_neg = TRUE;
		arg *= -1;
	}
	new_str = ft_itoa(arg);
	if (*new_str == '0' && node->width_len > 0)
		node->content = get_filler(new_str, node, &node->width_len);
	else if (*new_str != '0')
		update_content(new_str, node);
	node->done = 1;
}

