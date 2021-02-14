/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:59:38 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/14 00:13:52 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
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
			return (word_count);
		s++;
	}
	is_word == 'y' ? word_count += 1 : word_count;
	return (word_count);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	sep_index;
	size_t	next_index;
	size_t	words_nbr;
	size_t	i;

	if (!s || !c)
		return (NULL);
	i = -1;
	sep_index = 0;
	words_nbr = ft_count_words(s, c);
	if (!(arr = malloc(sizeof(char *) * (words_nbr + 1))))
		return (NULL);
	while (++i < words_nbr)
	{
		while (s[sep_index] == c)
			sep_index = ft_strchr(&s[sep_index], c) - s + 1;
		next_index = ft_strchr(&s[sep_index], c)
		? ft_strchr(&s[sep_index], c) - s - sep_index
		: ft_strlen(s) - sep_index;
		arr[i] = ft_substr(s, sep_index, next_index);
		sep_index = ft_strchr(&s[sep_index], c) - s + 1;
	}
	arr[i] = 0;
	return (arr);
}

int					main(void)
{


		printf("%s", *ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i'));

}
