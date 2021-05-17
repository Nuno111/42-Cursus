/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:17:40 by ngregori          #+#    #+#             */
/*   Updated: 2021/05/17 22:59:49 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	write_image_data(t_game *game, int fd)
{
	int	*inverse_img;
	int	i;
	int size;

	size = game->stg.h * game->stg.w;
	i = 0;
	inverse_img = malloc(sizeof(int) * size);
	if (!inverse_img)
		exit_game(game, "Error\nCoulnd't allocate memory for new image");
	while (size > 0)
	{

	}

}

static	void	write_header_data(t_game *game, int fd)
{
	write(fd, &game->bpm_header.bf_type, 2);
	write(fd, &game->bpm_header.bf_size, 4);
	write(fd, &game->bpm_header.bf_reserved1, 2);
	write(fd, &game->bpm_header.bf_reserved2, 2);
	write(fd, &game->bpm_header.bf_type, 4);
	write(fd, &game->bpm_info_header.bi_size, 4);
	write(fd, &game->bpm_info_header.bi_width, 4);
	write(fd, &game->bpm_info_header.bi_height, 4);
	write(fd, &game->bpm_info_header.bi_planes, 2);
	write(fd, &game->bpm_info_header.bi_bitcount, 2);
	write(fd, &game->bpm_info_header.bi_compression, 4);
	write(fd, &game->bpm_info_header.bi_sizeimage, 4);
	write(fd, &game->bpm_info_header.bi_xpelspermeter, 4);
	write(fd, &game->bpm_info_header.bi_ypelspermeter, 4);
	write(fd, &game->bpm_info_header.bi_clrused, 4);
	write(fd, &game->bpm_info_header.bi_clrimportant, 4);
}

void    save_and_exit(t_game *game)
{
	int				fd;

	game->bpm_header.bf_type = "BM";
	game->bpm_header.bf_size = game->stg.h * game->stg.w + 54;
	game->bpm_header.bf_reserved1 = 0;
	game->bpm_header.bf_reserved2 = 0;
	game->bpm_header.bf_offbits = 54;
	game->bpm_info_header.bi_size = 40;
	game->bpm_info_header.bi_width = game->stg.w;
	game->bpm_info_header.bi_height = game->stg.h;
	game->bpm_info_header.bi_planes = 1;
	game->bpm_info_header.bi_bitcount = game->img.bpp;
	game->bpm_info_header.bi_compression = 0;
	game->bpm_info_header.bi_sizeimage = 0;
	game->bpm_info_header.bi_xpelspermeter = 2835;
	game->bpm_info_header.bi_ypelspermeter = 2835;
	game->bpm_info_header.bi_clrused = 0;
	game->bpm_info_header.bi_clrimportant = 0;
	fd = open("rendered_image.bmp", O_CREAT | O_WRONLY);
	if (fd == -1)
		exit_game(game, "Error\nCouldn't open a bmp file for writing.");
	write_header_data(game, fd);
	close(fd);
	exit_game(game, NULL);
}
