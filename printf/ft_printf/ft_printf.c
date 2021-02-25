/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:15:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/25 01:08:18 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_percent(char *s, char **to_print, va_list ap, int index)
{
	if (s[index + 1] == '%')
	{
		add_letter(s[index], to_print);
		return (index += 2);
	}
	else if (s[index + 1])
		index = manage_node(s, to_print, ap, ++index);
	return (++index);
}

void	add_letter(char s, char **to_print)
{
	char *new;

	if (*to_print == NULL)
	{
		*to_print = ft_strdup("");
	}
	new = ft_strjoin_c(*to_print, s);
	free(*to_print);
	*to_print = new;
}

int		iterate_string(char *s, char **to_print, va_list ap)
{
	int	i;
	int length;

	length = ft_strlen(s);
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			add_letter(s[i], to_print);
			i++;
		}
		else
			i = handle_percent(s, to_print, ap, i);
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
