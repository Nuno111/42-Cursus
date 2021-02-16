/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:59:38 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/16 02:11:19 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_words(char const *s, char c)
{
	size_t	word_count;
	char	is_word;

	word_count = 0;
	is_word = 'n';
	while (*s)
	{
		is_word == 'y' ? word_count += 1 : word_count;
		while (*s != c && *s != '\0')
			s++;
		if (*s == c && *(s + 1) != c)
			is_word = 'y';
		else if (*s != '\0')
			is_word = 'n';
		else
			return (++word_count);
		s++;
	}
	is_word == 'y' ? word_count += 1 : word_count;
	return (word_count);
}

void		ft_fill_array(size_t words_nbr, char **arr, const char *s, char c)
{
	size_t	sep_index;
	size_t	next_index;
	size_t	i;

	i = -1;
	sep_index = 0;
	while (++i < words_nbr)
	{
		while (s[sep_index] == c)
			sep_index = ft_strchr(&s[sep_index], c) - s + 1;
		next_index = ft_strchr(&s[sep_index], c)
		? ft_strchr(&s[sep_index], c) - s - sep_index
		: ft_strlen(s) - sep_index;
		if (next_index == 0)
			arr[i] = NULL;
		else
			arr[i] = ft_substr(s, sep_index, next_index);
		sep_index = ft_strchr(&s[sep_index], c) - s + 1;
	}
	arr[i] = 0;
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words_nbr;

	if (!s)
		return (NULL);
	words_nbr = ft_count_words(s, c);
	if (!(arr = malloc(sizeof(char *) * (words_nbr + 1))))
		return (NULL);
	ft_fill_array(words_nbr, arr, s, c);
	return (arr);
}
