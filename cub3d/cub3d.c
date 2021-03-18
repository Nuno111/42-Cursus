/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:32:40 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/17 21:35:44 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     main(int argc, char *argv[])
{
	t_scene settings;

	init_settings(&settings);
	if (argc != 2)
		error_and_exit(&settings, "Two arguments needed");
	parse_settings(&settings, argv[1]);
	render_game(&settings);
	free_settings(&settings);
	printf("ok");
	return (OK);
}
