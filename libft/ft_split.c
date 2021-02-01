/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:59:38 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/01 19:52:51 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t		ft_count_words(char const *s, char c)
{
	size_t	word_count;
	char	is_word;

	word_count = -1;
	is_word = 'n';
	while (*s)
	{
		is_word == 'y' ? word_count+= 1 : word_count;
		while (*s != c && *s != '\0')
			s++;
		if (*s == c && *(s - 1) != c)
			is_word = 'y';
		else if (*s != '\0')
			is_word = 'n';
		else
			return (word_count);
		s++;
	}
	is_word == 'y' ? word_count +=1 : word_count;
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char **arr;
	char *sep_index;
	char *sep_index2;
	size_t words_nbr;
	size_t i;

	words_nbr = ft_count_words(s, c);
	i = 0;
	if (!s || !c)
		return (NULL);
	if(!(malloc(sizeof(char *) * (words_nbr + 1))))
		return (NULL);
	while (i < words_nbr)
	{
		sep_index = ft_strchr(s, c);
		sep_index2 = ft_strchr(sep_index, c);
		arr[i] = strdup(sep_index, sep_index2)
	}
}

int main(void)
{
	ft_split("i,i,,,,i,z,", ',');
}
