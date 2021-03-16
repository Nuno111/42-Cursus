/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_settings.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:40:46 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/16 22:00:34 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_SETTINGS_H
#define VALIDATE_SETTINGS_H

# include "../cub3d.h"

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef	struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;


typedef struct		s_scene
{
	t_res	*res;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sprite;
	t_rgb	*floor;
	t_rgb	*ceil;
	t_list	*tmp_map;
	char	**map;
	bool	valid;
}					t_scene;

void	validate_map(t_scene *settings);
void	error_and_exit(t_scene *settings, char *error_log);
void	free_settings(t_scene *settings);
char	**linked_to_array(t_scene *settings, t_list *head);
void	verify_walls(t_scene *settings);
bool	verify_str(char *str, bool whole);
void	verify_position(t_scene *settings);
char	*replace_tabs(char *str);
bool    validate_name(char *file);
void	validate_floor_ceil(t_scene *settings, t_rgb **floor_or_ceil, char **strs);
void	validate_r(t_scene *settings, char **strs);
void	validate_textures(t_scene *settings, char **path, char **strs);
void	parse_settings(t_scene *settings, char *file);

#endif
