/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:40:42 by ngregori          #+#    #+#             */
/*   Updated: 2021/01/25 16:58:43 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *ptr;

	if (!nmemb || !size || nmemb * size > 2147483647)
		return (NULL);
	ptr = malloc(nmemb * size);
	return (ft_memset(ptr, 0, nmemb * size));
}
