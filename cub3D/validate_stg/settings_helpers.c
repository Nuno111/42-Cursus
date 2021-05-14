/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stg_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:21:32 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/22 12:55:39 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	validate_string(char *str)
{
	int i;
	int	num;
	int comma;

	if (!str)
		return (false);
	i = 0;
	num = 0;
	comma = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			num++;
		else if (str[i] == ',' && num <= 3)
		{
			comma++;
			num = 0;
		}
		else if (str[i] == ',')
			return (false);
		if (comma > 2 || num > 3 || (!ft_isdigit(str[i]) && str[i] != ','))
			return (false);
		i++;
	}
	return (true);

}


void	free_stg(t_scene *stg)
{
	if (stg->no)
		free(stg->no);
	if (stg->so)
		free(stg->so);
	if (stg->we)
		free(stg->we);
	if (stg->ea)
		free(stg->ea);
	if (stg->sprite)
		free(stg->sprite);
	if (stg->floor)
		free(stg->floor);
	if (stg->ceil)
		free(stg->ceil);
	if (stg->tmp_map)
		ft_free_list(&stg->tmp_map);
	if (stg->map)
		ft_freearrays(stg->map);
	if (stg->line)
		free(stg->line);
}
