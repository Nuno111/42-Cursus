/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:15:06 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/06 17:03:50 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_convert(const char *nbr, int sign)
{
	int			i;
	long long	result;

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
	int i;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+')
	{
		if (ft_isdigit(nptr[i + 1]))
			result = ft_convert(&nptr[i + 1], 1);
		else
			return (0);
	}
	else if (nptr[i] == '-')
	{
		if (ft_isdigit(nptr[i + 1]))
			result = ft_convert(&nptr[i + 1], -1);
		else
			return (0);
	}
	else if (ft_isdigit(nptr[i]))
		result = ft_convert(&nptr[i], 1);
	else
		return (0);
	return (result);
}
