/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 20:35:29 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/09 14:04:21 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_get_length(size_t n)
{
	size_t length;

	length = 1;
	while (n > 9)
	{
		n /= 10;
		length++;
	}
	return (length);
}

void		ft_convert_nbr(char *arr, long long n, size_t index)
{
	if (n > 9)
		ft_convert_nbr(arr, n / 10, index - 1);
	arr[index] = n > 9 ? n % 10 + 48 : n + 48;
}

char		*ft_itoa(long n)
{
	char		*arr;
	long long	nbr;
	size_t		length;

	nbr = n < 0 ? (long long)n * -1 : n;
	length = n < 0 ? ft_get_length(nbr) + 1 : ft_get_length(nbr);
	if (!(arr = malloc(sizeof(char) * length + 1)))
		return (NULL);
	if (n < 0)
	{
		arr[0] = '-';
		ft_convert_nbr(arr, nbr, length - 1);
	}
	else
	{
		ft_convert_nbr(arr, nbr, length - 1);
	}
	arr[length] = '\0';
	return (arr);
}
