/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:57:03 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/20 13:27:28 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	handle_d(char *s, node *to_add, va_list ap)
{
	//conditions of padding t be handled here
	if (to_add->pad_len > 0)
		to_add->has_pad = TRUE;
	if (to_add->from_arg)
		handle_padding(s, to_add);
	to_add->content = ft_itoa(va_arg(ap, int));
}
