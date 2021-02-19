/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:15:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/19 16:40:31 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int		manage_node(char *str_to_print, char *s, va_list ap, int *count, int i)
{
	node to_add;

	to_add.i = i;
	to_add.has_pad = 0;
	to_add.pad_is_zero = 0;
	to_add.left_align = 0;
	to_add.pad_len = NULL;
	flags(s, to_add, i);
	width(s, to_add);
	precision(s, to_add);
	size(s, to_add);
}

int		iterate_string(char *str_to_print, char *s, va_list ap, int *count)
{
	int	i;
	int length;

	length = ft_strlen(s);
	i = 0;
	while (s[i])
	{
		if (s[i] != '%' || (s[i] == '%' && s[i - 1] == '%'))
		{
			add_letter(s[i], count, str_to_print);
			i++;
		}
		else if (s[i] == '%' && s[i - 1] != '%')
			i = manage_node(str_to_print, s[++i], ap, &count, i);
		else
			i++;
		if (i < 0)
			return (-1);
		else if (i > length)
				return (0);
	}
	return (0);
}

int		ft_printf(const char *s, ...)
{
	va_list ap;
	char *str_to_print;
	int status;
	int count;

	if (!s)
		return (-1);
	va_start(ap, s);
	status = iterate_string(str_to_print, s, ap, &count);
	va_end(ap);
	if (status != 0)
		return (count);
	return (status);
}

int		main(void)
{
	long long b = 111111111111111111;

	printf("HEllo %lld", b);
	ft_printf("HEllo %lld", b);
}

// Flags -0
// Width *
// precision .
// sizes

// Options
// Padding is only added if necessary, length argument < padding
// -0 or 0-	padding = spaces	aligned left, 0 is ignored
// * 		padding = spaces	determined by argument
// .*		padding = 0			determined by argument
// *.		padding = spaces	determined by argument
// . 		padding = spaces	determined by preceding number
// 0d 		padding = 0			determined by preceding number
