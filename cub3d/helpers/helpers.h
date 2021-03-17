/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:22:34 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/17 21:23:40 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
#define HELPERS_H

#include "../cub3d.h"

void	error_and_exit(t_scene *settings, char *error_log);
void	init_settings(t_scene *settings);
void	free_settings(t_scene *settings);

#endif
