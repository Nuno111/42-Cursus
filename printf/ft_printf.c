/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:15:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/18 18:59:09 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		ft_printf(const char *s, ...)
{
	va_list ap;
	size_t i;
	int		count;

	count = 0;
	i = 0;
	va_start(ap, s);


	while (s[i] != '%' && s[i])
	{
		ft_putchar(s[i]);
		count++;
		i++;
	}
	if (!s[i])
		return (count);
	i++;
	if (s[i] == 'd')
		ft_putnbr(va_arg(ap, long long));
	while (s[++i])
	{
		ft_putchar(s[i]);
	}
	ft_putchar('\n');
	va_end(ap);
	return (1);
}

int		main(void)
{
	long long b = 111111111111111111;

	printf("HEllo %.155lld", b);
}

// Options
// Padding is only added if necessary, length argument < padding
// -0 or 0-	padding = spaces	aligned left, 0 is ignored
// * 		padding = spaces	determined by argument
// .*		padding = 0			determined by argument
// *.		padding = spaces	determined by argument
// . 		padding = spaces	determined by preceding number
// 0d 		padding = 0			determined by preceding number
