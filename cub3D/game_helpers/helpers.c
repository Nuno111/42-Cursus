/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:05:38 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/31 21:07:49 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    error_and_exit_game(t_game *game, char *error_log)
{
	free_settings(&game->settings);
	printf("%s.\n", error_log);
}
