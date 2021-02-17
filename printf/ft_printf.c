/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:15:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/17 13:45:20 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *s, ...)
{
	va_list ap;
	size_t i;

	i = 0;
	va_start(ap, s);

	while (s[i] != '%')
	{
		ft_putchar(s[i]);
		i++;
	}
	if (s[++i] == 'd')
	{
		ft_putnbr(va_arg(ap, long));
	}
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

	ft_printf("Hello number %d", 1);
}
