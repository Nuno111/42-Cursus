/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:57:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/05 17:43:03 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_filler(char *new_str, long len, bool pad_is_zero)
{
	char	*filler;
	int		new_len;

	new_len = len - ft_strlen(new_str);
	filler = malloc(sizeof(char) * new_len + 1);
	if (!filler)
		return (NULL);
	if (pad_is_zero)
		ft_memset(filler, '0', new_len);
	else
		ft_memset(filler, ' ', new_len);
	filler[new_len] = '\0';
	return (filler);
}

char	*truncate_str(char *new_str, t_node *n)
{
	char *new;

	new = ft_substr(new_str, 0, n->prec_len);
	free(new_str);
	return (new);
}

void	update_padding(t_node *n, long *w_or_p_len, bool from_arg)
{
	int		i;
	char	*str_len;

	if (!n->has_prec)
		n->has_width = true;
	i = 0;
	if (from_arg)
		*w_or_p_len = va_arg(n->ap, int);
	else
	{
		i = 0;
		while (ft_isdigit(n->s[n->i + i]))
			i++;
		str_len = ft_substr(n->s, n->i, i);
		*w_or_p_len = ft_atoi(str_len);
		free(str_len);
		n->i += i;
	}
	if (*w_or_p_len < 0)
		handle_negative_wp(w_or_p_len, n);
}

char	*str_join_free(char **beg, char **end)
{
	char	*tmp;

	tmp = ft_strjoin(*beg, *end);
	free(*beg);
	free(*end);
	return (tmp);
}
