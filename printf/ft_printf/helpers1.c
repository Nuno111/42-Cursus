/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 22:15:53 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/02 00:39:13 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_negative_wp(long *w_or_p_len, t_node *n)
{
	if (!n->has_prec)
	{
		n->left_align = true;
		*w_or_p_len *= -1;
		if (n->pad_is_zero)
			n->pad_is_zero = false;
	}
	else
	{
		n->has_prec = false;
		*w_or_p_len = 0;
	}
}
