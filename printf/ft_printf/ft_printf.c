/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:15:19 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/20 22:26:36 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_node(char *str_to_print, char *s, va_list ap, int i)
{
	node to_add;
	char *new_str;

	to_add.i = i;
	to_add.has_pad = FALSE;
	to_add.pad_is_zero = FALSE;
	to_add.left_align = FALSE;
	to_add.pad_len = FALSE;
	to_add.from_arg = FALSE;
	to_add.done = FALSE;
	while (to_add.done != TRUE)
		handle_cases(s, &to_add, ap);
	if (to_add.content)
	{
		new_str = ft_strjoin(str_to_print, to_add.content);
		free(to_add.content);
		if (str_to_print)
			free(str_to_print);
		str_to_print = new_str;
	}
	return (to_add.i);
}

int		iterate_string(char **str_to_print, char *s, va_list ap)
{
	int	i;
	int length;

	length = ft_strlen(s);
	i = 0;
	while (s[i])
	{
		if (s[i] != '%' /*|| (s[i] == '%' && s[i - 1] == '%')*/)
		{
			add_letter(s[i], str_to_print);
			i++;
		}
		else if (s[i] == '%' && s[i - 1] != '%')
		{
			i++;
			i = manage_node(*str_to_print, &s[i], ap, i);
		}
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

	str_to_print = NULL;
	if (!s)
		return (-1);
	va_start(ap, s);
	status = iterate_string(&str_to_print, (char *)s, ap);
	va_end(ap);

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
