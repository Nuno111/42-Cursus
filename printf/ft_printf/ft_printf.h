#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"

typedef int bool;
# define TRUE 1
# define FALSE 0

typedef struct		node_t
{
    char            *content;
	size_t			i;
	int				pad_len;
    bool            left_align;
    bool            has_pad;
    bool            from_arg;
    bool            pad_is_zero;
	bool			done;
}					node;


#endif
