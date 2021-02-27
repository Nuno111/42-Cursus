/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 22:15:53 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/27 13:48:07 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_negative_wp(int *w_or_p_len, t_node *node)
{
	if (!node->has_prec)
	{
		node->left_align = true;
		*w_or_p_len *= -1;
	}
	else
	{
		node->has_prec = false;
		*w_or_p_len = 0;
	}
}
