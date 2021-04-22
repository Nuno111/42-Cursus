/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:32:40 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/22 12:48:22 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     main(int argc, char *argv[])
{
	t_game game;

	init_settings(&game.settings);
	if (argc != 2)
		error_and_exit_settings(&game.settings, "Two arguments needed");
	parse_settings(&game.settings, argv[1]);
	render_game(&game);
	return (0);
}
