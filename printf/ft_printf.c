/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:15:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/17 23:38:55 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		ft_printf(const char *s, ...)
{
	va_list ap;
	size_t i;

	i = 0;
	va_start(ap, s);


	while (s[i] != '%' && s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	if (s[i])
		i++;
	if (s[i] == 'd')
		ft_putnbr(va_arg(ap, unsigned int));
	else if ()
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
	printf("HEllo %0-10X", 10);
}

// Options
// Padding is only added if necessary, length argument < padding
// -0 or 0-	padding = spaces	aligned left, 0 is ignored
// * 		padding = spaces	determined by argument
// .*		padding = 0			determined by argument
// *.		padding = spaces	determined by argument
// . 		padding = spaces	determined by preceding number
// 0d 		padding = 0			determined by preceding number
