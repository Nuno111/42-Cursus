/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:54:21 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/03 16:47:59 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

int	main(void)
{
	ft_printf(" %s %s ", "0", "1");
	printf(" %s %s ", "0", "1");
}

// strlen (arg) < precision then add padding // if left alig width is ignored
