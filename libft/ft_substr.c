/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 01:32:54 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/12 01:19:20 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;

	if (!s)
		return (NULL);
	sub_str = malloc(sizeof(char) * len + 1);
	if (!sub_str)
		return (NULL);
	if (start < ft_strlen(s))
	{
		ft_strlcpy(sub_str, &s[start], len + 1);
		return (sub_str);
	}
	else
		sub_str[0] = '\0';
	return (sub_str);
}
