/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 01:18:44 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/01 12:19:52 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_width(char *c, t_node *node)
{
	char	*filler;

	filler = get_filler(" ", node->width_len, node->pad_is_zero);
	if (node->left_align)
		node->content = ft_strjoin(c, filler);
	else
		node->content = ft_strjoin(filler, c);
	free(filler);
}

void	handle_c(t_node *node, va_list ap)
{
	char	arg;

	arg = va_arg(ap, int);

	if (!ft_isprint(arg))
	{
		node->content = malloc(sizeof(char) * 1);
		node->content[0] = arg;
	}
	else if (node->width_len > 1)
		handle_width(&arg, node);
	else
		node->content = ft_strdup(&arg);

	node->done = 1;
}