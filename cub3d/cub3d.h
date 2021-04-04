/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:32:51 by ngregori          #+#    #+#             */
/*   Updated: 2021/04/04 20:56:00 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "libft.h"
# include <math.h>
# include <float.h>

# define deg_to_rad(degrees) ((degrees) * M_PI / 180.0)
# define rad_to_deg(radians) ((radians) * 180.0 / M_PI)

typedef	struct 	s_texture
{
    void    *img;
    char    *relative_path;
    int     width;
    int     height;
}				t_texture;

typedef struct	s_img
{
    void		*img;
    char		*addr;
    int			bits_per_pixel;
    int			line_length;
    int			endian;
}				t_img;

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

typedef struct s_tile_size
{
	size_t x;
	size_t y;
}				t_tile_size;

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
	t_tile_size tile_size;
}					t_scene;

typedef struct	s_circle
{
	double	x;
	double	y;
	double	ang;
	double	radius;
	int		color;
}				t_circle;

typedef struct s_square
{
	double	x;
	double	y;
	double	size;
	int		color;
}				t_square;

typedef struct	s_line
{
	double	x;
	double	y;
	double	direction;
	double	size;
	int		color;
}				t_line;

typedef struct s_ray
{
	t_line ray;
	double	hrzt_hit_x;
	double	hrzt_hit_y;
	double	vrtc_hit_x;
	double	vrtc_hit_y;
	double	distance;
	bool	facing_up;
	bool	facing_right;
	bool	hrzt_hit;
	bool	vrtc_hit;
}				t_ray;

typedef struct s_player
{
	t_circle	circle;
	t_line		line;
	double rotation_angle;
	double move_speed;
	double rotation_speed;
	double		fov_ang;
	int turn_dir;
	int walk_dir;
	int			wall_wid;
	bool strafe;
	t_ray		**rays;
	int			num_rays;
}				t_player;

typedef struct s_intercect
{
	double x;
	double y;
	double x_step;
	double y_step;
	int		x_offset;
	int		y_offset;
}				t_intercect;


typedef struct s_game
{
	t_player	player;
	t_square	map_tile;
	t_scene		settings;
	t_vars		vars;
	t_img		img;
}				t_game;

/*
Colours
*/
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

/*
validate_settings
*/
void	error_and_exit_settings(t_scene *settings, char *error_log);
void	init_settings(t_scene *settings);
void	free_settings(t_scene *settings);
void	validate_map(t_scene *settings);
char	**linked_to_array(t_scene *settings, t_list *head);
void	verify_position(t_scene *settings);
bool	verify_str(char *str, bool whole);
char	*replace_tabs(char *str);
bool    validate_name(char *file);
void	validate_floor_ceil(t_scene *settings, t_rgb **floor_or_ceil, char **strs);
void	validate_r(t_scene *settings, char **strs);
void	validate_textures(t_scene *settings, char **path, char **strs);
void	parse_settings(t_scene *settings, char *file);
void	create_fake_map(t_scene *settings);
void	verify_walls(t_scene *settings, char **m);

/*
Drawing
*/
void	draw_inner_circle(t_img *img, t_circle circle);
void	draw_line(t_img *img, t_line line);
void	draw_circle(t_img *img, t_circle circle);
void	draw_square(t_img *img, t_square square);

int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		handle_key_press(int keycode, t_vars *vars);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void    render_game(t_game *game);
void	create_minimap(t_scene *settings, t_game *game);
void	init_player(t_game *game);
void    update_game(t_game *game);
void    error_and_exit_game(t_game *game, char *error_log);
void	cast_rays(t_game *game);
bool	is_wall(double x, double y, t_game *game);
void	render_rays(t_game *game);
double		get_distance(double x, double y, double hit_x, double hit_y);
double		normalize_angle(double ray_ang);
void		get_horizontal_intercection(t_game *game, t_ray *ray);
void		get_vertical_intercection(t_game *game, t_ray *ray);
void	render_walls(t_game *game);

#endif
