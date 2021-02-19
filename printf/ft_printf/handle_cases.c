/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:28:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/19 21:37:49 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	handle_zero(char *s, node *to_add)
{
	if (s[to_add->i - 1] != '-')
	{
		to_add->has_pad = 1;
		to_add->i++;
	}
	else
	{
		to_add->has_pad = 1;
		to_add->pad_is_zero = 1;
		to_add->left_align = 0;
		to_add->i++;
	}
}

void	handle_asterisk(node *to_add)
{
		to_add->has_pad = 1;
		to_add->from_arg = 1;
		to_add->i++;
}

void	handle_dot(node *to_add)
{
	to_add->can_trunc = 1;
}

