/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_dependents.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:28:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/22 12:41:29 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_zero(char *s, node *to_add)
{
	if (s[to_add->i - 1] == '-')
	{
		to_add->has_pad = TRUE;
		to_add->i++;
	}
	else
	{
		to_add->has_pad = TRUE;
		to_add->pad_is_zero = TRUE;
		to_add->left_align = FALSE;
		to_add->i++;
	}
}

void	handle_asterisk(node *to_add)
{
		to_add->has_pad = TRUE;
		to_add->from_arg = TRUE;
		to_add->i++;
}

void	handle_dot(node *to_add)
{
	to_add->pad_is_zero = TRUE;
	to_add->has_pad = TRUE;
	to_add->i++;
}

int		handle_percent(int index, char *s, char **str_to_print, va_list ap)
{
	if (s[index + 1] == '%')
	{
		add_letter(s[index], str_to_print);
		return (index += 2);
	}
	else if (s[index + 1])
		index = manage_node(str_to_print, s, ap, ++index);
	return (++index);
}

