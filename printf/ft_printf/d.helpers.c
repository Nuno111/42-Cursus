/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 01:40:04 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/25 01:42:03 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_padding(char *new_str, t_node *node)
{
	size_t	length;
	int		*wid_or_pre;
	char	*filler;
	char	*tmp;

	if (node->can_trunc && (int)ft_strlen(new_str) > node->prec_len)
		new_str = truncate_str(new_str, node);
	length = ft_strlen(new_str);
	if (node->prec_len >= node->width_len)
	{
		wid_or_pre = &node->prec_len;
		node->pad_is_zero = TRUE;
	}
	else if (node->has_width)
		wid_or_pre = &node->width_len;
	filler = get_filler(new_str, node, wid_or_pre);
	if ((int)length > *wid_or_pre)
		node->content = new_str;
	else if (node->left_align)
		node->content = ft_strjoin(new_str, filler);
	else if (node->is_neg)
	{
		tmp = ft_strjoin("-", filler);
		node->content = ft_strjoin(tmp, new_str);
		free(tmp);
	}
	else
		node->content = new_str;
	free(filler);
	free(new_str);
}

void	update_content(char *new_str, t_node *node)
{

	if (node->has_prec || node->has_width)
		manage_padding(new_str, node);
	else if (node->can_trunc && (int)ft_strlen(new_str) < node->prec_len)
		new_str = truncate_str(new_str, node);
	else
		node->content = new_str;
}
