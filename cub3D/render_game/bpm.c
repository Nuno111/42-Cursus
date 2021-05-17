/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:17:40 by ngregori          #+#    #+#             */
/*   Updated: 2021/05/17 12:24:08 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    save_and_exit(t_game *game)
{
	int				fd;
	t_file_header	bm_header;
	t_info_header	bm_info_header;

	bm_header.bf_type = "BM";
	bm_header.bf_size = game->stg.h * game->stg.w;
	bm_header.bf_reserved1 = 0;
	bm_header.bf_reserved2 = 0;
	bm_header.bf_offbits = 54;
	bm_info_header.bi_size = 40;
	bm_info_header.bi_width = game->stg.w;
	bm_info_header.bi_height = game->stg.h;
	bm_info_header.bi_planes = 1;
	bm_info_header.bi_bitcount = game->img.bpp;
	fd = open("rendered_image.bmp", O_CREAT);
	close(fd);
	exit_game(game, NULL);
}
