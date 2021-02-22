/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:15:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/22 15:37:55 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list ap;
	char *to_print;
	int status;
	int	length;

	to_print = NULL;
	if (!s)
		return (-1);
	va_start(ap, s);
	status = iterate_string((char *)s, &to_print, ap);
	va_end(ap);
	if (status < 0)
		return (status);
	if (to_print)
	{
		ft_putstr(to_print);
		length = ft_strlen(to_print);
		free(to_print);
		return (length);
	}
	return (status);
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
