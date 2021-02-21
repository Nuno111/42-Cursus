/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:58:16 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/21 18:49:07 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_c(char const *s1, char c)
{
	size_t	length;
	char	*arr;

	if (!c)
		return (NULL);
	length = ft_strlen(s1);
	if (!(arr = malloc(sizeof(char) * (length + 1) + 1)))
		return (NULL);
	ft_strlcpy(arr, s1, length + 1);
	arr[length] = c;
	arr[length + 1] = '\0';
	return (arr);
}
