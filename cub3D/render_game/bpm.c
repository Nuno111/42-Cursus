/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:17:40 by ngregori          #+#    #+#             */
/*   Updated: 2021/05/14 16:56:01 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    save_and_exit(t_game *game)
{
	int fd;

	fd = open("rendered_image.bmp", O_RDWR);
	ft_putchar_fd('B', fd);
	ft_putchar_fd('M', fd);
	ft_putnbr_fd(game->settings.w * game->settings.h + 40, fd);
	close(fd);
	exit_game(game, NULL);
}
