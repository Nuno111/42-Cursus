/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:17:41 by ngregori          #+#    #+#             */
/*   Updated: 2021/01/25 14:38:11 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t src_length;
	size_t dst_length;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (!dst || !src || !size)
		return (dst_length + src_length);
	i = 0;
	while (dst[dst_length + i] && src[i] && i <= size)
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	if (dst[dst_length + i])
		dst[dst_length + i] = '\0';
	return (dst_length + i);
}
