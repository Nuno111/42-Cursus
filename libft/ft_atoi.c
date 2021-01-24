/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:15:06 by ngregori          #+#    #+#             */
/*   Updated: 2021/01/24 17:12:06 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_convert(const char *nbr, int sign)
{
	int		i;
	long	result;

	result = 0;
	i = 0;
	while (ft_isdigit(nbr[i]))
	{
		result = result * 10 + nbr[i] - '0';
		i++;
	}
	return ((int)(result * sign));
}

int				ft_atoi(const char *nptr)
{
	int result;

	if (nptr[0] == '+')
	{
		if (ft_isdigit(nptr[1]))
			result = ft_convert(&nptr[1], 1);
		else
			return (0);
	}
	else if (nptr[0] == '-')
	{
		if (ft_isdigit(nptr[1]))
			result = ft_convert(&nptr[1], -1);
		else
			return (0);
	}
	else if (ft_isdigit(nptr[0]))
		result = ft_convert(&nptr[0], 1);
	else
		return (0);
	return (result);
}
