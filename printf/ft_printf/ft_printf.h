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
	bool			can_trunc;
	char			type;
}					node;

int		manage_node(char *str_to_print, char *s, va_list ap, int i);
int		iterate_string(char *str_to_print, char *s, va_list ap);
int		ft_printf(const char *s, ...);
void	handle_padding(char *s, node *to_add, va_list ap);
void	handle_types(char *s, node *to_add, va_list ap);
void	handle_cases(char *s, node *to_add, va_list ap);
void	handle_zero(char *s, node *to_add);
void	handle_asterisk(node *to_add);
void	handle_dot(node *to_add);
void	update_content(char *s, node *to_add, char *new_str);
void	handle_d(char *s, node *to_add, va_list ap);


#endif
