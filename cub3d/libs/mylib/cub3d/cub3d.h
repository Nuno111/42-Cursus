#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

typedef struct		s_res
{
	int		x;
	int		y;
}					t_res;

typedef struct		s_scene
{
	t_res	res;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sprite;
	char	**floor;
	char	**ceil;
}					t_scene;

bool	parse_name(char *map);
bool	parse_settings(char *map);

#endif
