/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:31:58 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/20 13:15:16 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	handle_padding(char *s, node *to_add, va_list ap)
{
	int		i;
	char	*str_len;
	int		int_len;

	if (to_add->from_arg)
		to_add->pad_len = va_arg(ap, int);
	else
	{
		i = 0;
		while (ft_is_numeric(s[to_add->i]))
		{
			to_add->i++;
			i++;
		}
		str_len = ft_substr(s, to_add->i, i);
		to_add->pad_len = ft_atoi(str_len);
		free(str_len);
		// need to add on types, if pane_len > 0 then to_add->has_pad = TRUE
		// depending on type
	}
}

void	handle_types(char *s, node *to_add, va_list ap)
{
	if (!s[to_add->i])
		return ;
	else if (ft_is_numeric(s[to_add->i]) && !to_add->from_arg)
		handle_padding(s, to_add, ap);
	else if (s[to_add->i] == 'c')
		handle_c(to_add);
	else if (s[to_add->i] == 's')
		handle_s(to_add);
	else if (s[to_add->i] == 'p')
		handle_p(to_add);
	else if (s[to_add->i] == 'd')
		handle_d(to_add);
	else if (s[to_add->i] == 'i')
		handle_i(to_add);
	else if (s[to_add->i] == 'u')
		handle_u(to_add);
	else if (s[to_add->i] == 'x')
		handle_x(to_add);
	else if (s[to_add->i] == 'X')
		handle_X(to_add);
}

void	handle_cases(char *s, node *to_add, va_list ap)
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
		handle_type(s, to_add, ap);

	// need to check another ignored case if 0 is present and has precision
}

