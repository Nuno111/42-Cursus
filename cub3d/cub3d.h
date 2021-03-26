/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:32:51 by ngregori          #+#    #+#             */
/*   Updated: 2021/03/26 20:34:01 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "libft.h"
# include <math.h>

# define deg_to_rad(degrees) ((degrees) * M_PI / 180.0)
# define rad_to_deg(radians) ((radians) * 180.0 / M_PI)


typedef struct	s_data
{
    void		*img;
    char		*addr;
    int			bits_per_pixel;
    int			line_length;
    int			endian;
}				t_data;

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

typedef struct  s_vars
{
        void    *mlx;
        void    *win;
}               t_vars;

typedef struct s_tsize
{
	size_t x;
	size_t y;
}				t_tsize;

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
	size_t	map_width;
	size_t	map_size;
	bool	valid;
	t_tsize tile_size;
}					t_scene;

typedef struct s_player
{
	int x;
	int y;
	int radius;
	int turn_dir;
	int walk_dir;
	float rotation_angle;
	int move_speed;
	float rotation_speed;
}				t_player;
/*
Colour operations
*/
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

int		handle_key_press(int keycode, t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	validate_map(t_scene *settings);
void	error_and_exit(t_scene *settings, char *error_log);
void	free_settings(t_scene *settings);
char	**linked_to_array(t_scene *settings, t_list *head);
bool	verify_str(char *str, bool whole);
void	verify_position(t_scene *settings);
char	*replace_tabs(char *str);
bool    validate_name(char *file);
void	validate_floor_ceil(t_scene *settings, t_rgb **floor_or_ceil, char **strs);
void	validate_r(t_scene *settings, char **strs);
void	validate_textures(t_scene *settings, char **path, char **strs);
void	parse_settings(t_scene *settings, char *file);
void    render_game(t_scene *settings);
void	error_and_exit(t_scene *settings, char *error_log);
void	init_settings(t_scene *settings);
void	free_settings(t_scene *settings);
void	create_fake_map(t_scene *settings);
void	verify_walls(t_scene *settings, char **m);
void	create_minimap(t_scene *settings, t_data *img);

#endif
