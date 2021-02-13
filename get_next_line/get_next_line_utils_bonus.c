/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:39:46 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/13 00:24:28 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == c)
		return (&((char *)s)[i]);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*newstr;
	size_t	length;

	length = ft_strlen(s);
	newstr = malloc(sizeof(char) * length + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s, length + 1);
	return (newstr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	length1;
	size_t	length2;
	char	*arr;

	length1 = s1 ? ft_strlen(s1) : 0;
	length2 = s2 ? ft_strlen(s2) : 0;
	if (!(arr = malloc(sizeof(char) * (length1 + length2) + 1)))
		return (NULL);
	ft_strlcpy(arr, s1, length1 + 1);
	ft_strlcpy(&arr[length1], s2, length2 + 1);
	free(s1);
	return (arr);
}
