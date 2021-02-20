/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:57:03 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/20 16:41:13 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	update_content(char *s, node *to_add, char *new_str)
{
	char 	*padding;
	int		i;
	int		padding_length;

	i = 0;
	padding_length = to_add->pad_len - ft_strlen(new_str);
	while (i < padding_length)
		i++;
	padding = malloc(sizeof(char) * i + 1);
	if (!padding)
		return ;
	if (to_add->pad_is_zero)
		ft_memset(padding, '0', i);
	else
		ft_memset(padding, ' ', i);
	to_add->content = ft_strjoin(padding, new_str);
	to_add->done = 1;
	free(padding);
	free(new_str);

}

void	handle_d(char *s, node *to_add, va_list ap)
{
	char *new_str;

	if (to_add->pad_len > 0)
		to_add->has_pad = TRUE;
	if (to_add->from_arg)
		handle_padding(s, to_add, ap);
	new_str = ft_itoa(va_arg(ap, int));
	if (to_add->pad_len > ft_strlen(new_str) && to_add->has_pad)
		update_content(s, to_add, new_str);
}

