/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 01:40:04 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/26 23:08:32 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		update_content(new_str, node);
	node->done = 1;
}

void	update_content(char *new_str, t_node *node)
{
	int		length;
	char	*filler;
	char	*tmp;

	length = ft_strlen(new_str);
	if (length > node->prec_len && length > node->width_len)
		node->content = new_str;
	else
	{
		if (node->has_prec && node->has_width)
		{
			if (node->prec_len >= node->width_len)
				filler = get_filler(new_str, node, &node->prec_len);
			else
				filler = get_filler(new_str, node, &node->width_len);
		}
		if (filler)
		{
			if (node->is_neg)
			{
				tmp = ft_strjoin("-", filler);
				node->content = ft_strjoin(tmp, new_str);
				free(tmp);
			}
			else if (node->left_align)
				node->content = ft_strjoin(new_str, filler);
			else
				node->content = ft_strjoin(filler, new_str);
		}
	}
}
