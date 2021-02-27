/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:54:21 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/27 17:50:35 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

int	main(void)
{
	ft_printf(" %-.2d ", 0);
	printf(" %-.2d ", 0);
}

// strlen (arg) < precision then add padding // if left alig width is ignored
