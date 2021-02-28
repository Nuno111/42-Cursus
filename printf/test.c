/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:54:21 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/28 00:12:18 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

int	main(void)
{
	ft_printf("%0*.10d*0-- \n",  21, -2147483648);
	printf("%0*.10d*0-- \n", 21, -2147483648);

}

// strlen (arg) < precision then add padding // if left alig width is ignored
