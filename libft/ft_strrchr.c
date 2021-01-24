/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:35:02 by ngregori          #+#    #+#             */
/*   Updated: 2021/01/24 20:45:53 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int length;

	length = ft_strlen(s);
	while (s[length])
	{
		if (s[length] == c)
			return ((char *)s[length]);
		length--;
	}
	return (NULL);
}
