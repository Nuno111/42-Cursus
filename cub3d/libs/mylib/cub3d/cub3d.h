#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

typedef struct		s_res
{
	int		x;
	int		y;
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
	t_rgb	*map;
}					t_scene;

bool	parse_name(char *map);
bool	parse_settings(char *map);

#endif
