/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 01:40:04 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/28 00:18:30 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static	void	add_minus(char **new_str)
{
	char	*tmp;

	tmp = ft_strjoin("-", *new_str);
	free(*new_str);
	*new_str = tmp;
}

static	void	update_content_d(char *new_str, t_node *node)
{
	char	*filler;

	filler = NULL;
	if ((long)ft_strlen(new_str) < node->prec_len)
		filler = get_filler(new_str, node->prec_len, true);
	else if ((long)ft_strlen(new_str) < node->width_len && node->is_neg)
	{
		filler = get_filler(new_str, node->width_len - 1, node->pad_is_zero);
		if (node->left_align)
			new_str = str_join_free(&new_str, &filler);
		else
			new_str = str_join_free(&filler, &new_str);

		add_minus(&new_str);
		node->content = new_str;
		return ;
	}
	if (filler)
		new_str = str_join_free(&filler, &new_str);
	if (node->is_neg)
		add_minus(&new_str);
	if ((node->left_align && node->has_prec && node->pad_is_zero && *new_str != '0') || node->width_len < (long)ft_strlen(new_str))
		node->content = new_str;
	else
	{
		filler = get_filler(new_str, node->width_len, node->pad_is_zero);
		if (node->left_align)
			node->content = str_join_free(&new_str, &filler);
		else
			node->content = str_join_free(&filler, &new_str);
	}
}

void	handle_d(t_node *node, va_list ap)
{
	char	*new_str;
	long	arg;

	new_str = NULL;
	arg = (long)va_arg(ap, int);
	if (arg < 0)
	{
		node->is_neg = true;
		arg *= -1;
	}
	new_str = ft_itoa(arg);
	if (*new_str == '0' && node->width_len > 0 && !node->prec_len && node->has_width)
	{
		node->content = get_filler("", node->width_len, node->pad_is_zero);
		free(new_str);
	}
	else if (*new_str == '0' && node->has_prec && !node->prec_len && !node->width_len)
		free(new_str);
	else
		update_content_d(new_str, node);
	node->done = 1;
}
