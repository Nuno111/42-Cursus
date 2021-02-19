/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:31:58 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/19 21:43:34 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	handle_types(char *s, node *to_add)
{
	int b = 0;
}

void	handle_cases(char *s, node *to_add)
{
	if (!s[to_add->i])
		return ;
	if (s[to_add->i] == '-')
	{
		to_add->left_align = TRUE;
		to_add->i++;
	}
	else if (s[to_add->i] == '0')
		handle_zero(s, to_add);
	else if (s[to_add->i] == '*')
		handle_asterisk(to_add);
	else if (s[to_add->i] == '.')
		handle_dot(to_add);
	else
		handle_type(s, to_add);

	// need to check another ignored case if 0 is present and has precision
}

