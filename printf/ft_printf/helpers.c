/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:31:58 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/19 16:40:29 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void    flags(char *s, node *to_add)
{
	if (s[to_add->i] == '-' && s[to_add->i])
	{
		to_add->left_align = 1;
		to_add->i++;
	}
}

void	width(char *s, node *to_add)
{
	if (!s[to_add->i])
		return ;
	if (s[to_add->i] == '0' && s[to_add->i - 1] != '-')
	{
		to_add->has_pad = 1;
		to_add->i++;
	}
	else if (s[to_add->i] == '0')
	{
		to_add->has_pad = 1;
		to_add->pad_is_zero = 1;
		to_add->i++;
	}
	else if (s[to_add->i] == '*')
	{
		to_add->has_pad = 1;
		to_add->
	}

	// need to check another ignored case if 0 is present and has precision
}

