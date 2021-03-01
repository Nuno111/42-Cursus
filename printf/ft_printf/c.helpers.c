/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 01:18:44 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/01 01:30:45 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_c(t_node *node, va_list ap)
{
	char	*new_str;
	char	*filler;
	char	arg;

	new_str = NULL;
	arg = va_arg(ap, char);
	if (node->width_len > 1)
		filler = get_filler(arg, node->width_len, node->pad_is_zero)


}
