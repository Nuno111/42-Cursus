/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:32:40 by ngregori          #+#    #+#             */
/*   Updated: 2021/05/14 13:54:57 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	init_settings(&game.settings);
	if (argc < 2 || argc > 3)
		error_and_exit_settings(&game.settings,
			"Error\nTwo or three arguments needed.");
	game.screenshot = false;
	if (argc == 3)
	{
		if (ft_strcmp("--save", argv[2]) == 0)
			game.screenshot = true;
		else
			error_and_exit_settings(&game.settings,
				"Error\nThird argument not properly formatted.");
	}
	parse_settings(&game.settings, argv[1]);
	render_game(&game);
	return (0);
}
