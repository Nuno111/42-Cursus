/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:54:21 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/27 00:18:01 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

int	main(void)
{
	ft_printf("%-4.2d \n", 0);
	printf("%-4.2d \n", 1);
}

// strlen (arg) < precision then add padding // if left alig width is ignored
