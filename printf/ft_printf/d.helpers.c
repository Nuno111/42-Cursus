/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 01:40:04 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/26 23:57:15 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*str_join_free(char **beg, char **end)
{
	char	*tmp;

	tmp = ft_strjoin(*beg, *end);
	free(*beg);
	free(*end);
	return (tmp);
}

static	void	add_minus(char **new_str)
{
	char	*tmp;

	tmp = ft_strjoin('-', *new_str);
	free(*new_str);
	*new_str = tmp;
}

static	void	update_content_d(char *new_str, t_node *node)
{
	char	*filler;
	char	*tmp;

	if (ft_strlen(new_str) < node->prec_len)
		filler = get_filler(new_str, node, &node->prec_len);
	if (filler)
		new_str = str_join_free(&filler, &new_str);
	if (node->is_neg)
		add_minus(&new_str);
	if ((node->left_align && node->has_prec) || node->width_len < ft_strlen(new_str))
		node->content = new_str;
	else
	{
		filler = get_filler(new_str, node, &node->width_len);
		if (node->left_align)
			node->content = str_join_free(&new_str, &filler);
		else
			node->content = str_join_free(&filler, &new_str);
	}
}

void	handle_d(t_node *node, va_list ap)
{
	char	*new_str;
	int		arg;

	new_str = NULL;
	arg = va_arg(ap, int);
	if (arg < 0)
		node->is_neg = TRUE;
	new_str = ft_itoa(-arg);
	if (*new_str == '0' && node->width_len > 0 && !node->prec_len && node->has_width)
		node->content = get_filler(new_str, node, &node->width_len);
	else if (*new_str == '0' && !node->width_len && !node->prec_len)
		node->done = 1;
	else
		update_content_d(new_str, node);
	node->done = 1;
}
