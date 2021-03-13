#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef	struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
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
	t_list	*map;
	bool	valid;
}					t_scene;

void	validate_floor_ceil(t_scene *settings, t_rgb *floor_or_ceil, char **strs);
void	validate_r(t_scene *settings, char **strs);
void	validate_map(t_scene *settings, char **strs);
void	validate_textures(t_scene *settings, char **path, char **strs);
bool	parse_settings(char *map);

#endif
