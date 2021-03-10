/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:22:37 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/10 23:35:36 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_r(t_scene *settings, char **strs)
{
	if (settings->res)
	{
		settings->valid = false;
		return ;
	}
}

void	validate_s(t_scene *settings, char **strs)
{
	if (settings->sprite)
	{
		settings->valid = false;
		return ;
	}

}

void	validate_f(t_scene *settings, char **strs)
{
	if (settings->floor)
	{
		settings->valid = false;
		return ;
	}

}

void	validate_c(t_scene *settings, char **strs)
{
	if (settings->ceil)
	{
		settings->valid = false;
		return ;
	}

}

void	validate_texture(t_scene *settings, char **path, char **strs)
{

}
