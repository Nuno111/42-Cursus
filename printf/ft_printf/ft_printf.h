#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

typedef int bool;
# define TRUE 1
# define FALSE 0


typedef struct		s_node
{
    char            *content;
	size_t			i;
	int				prec_len;
	int				width_len;
    bool            left_align;
    bool            has_prec;
    bool            has_width;
    bool            from_arg;
    bool            pad_is_zero;
	bool			done;
	bool			can_trunc;
	char			type;
}					t_node;

char	*truncate_str(char *new_str, t_node *node);
char	*get_width(char *new_str, t_node *node);
void	handle_hyphen(t_node *node);
int		handle_percent(char *s, char **to_print, va_list ap, int index);
void	add_letter(char s, char **to_print);
int		manage_node( char *s, char **to_print, va_list ap, int i);
int		iterate_string(char *s, char **to_print, va_list ap);
int		ft_printf(const char *s, ...);
void	handle_padding(char *s, t_node *node, va_list ap, int *w_or_l, bool from_arg);
void	handle_types(char *s, t_node *node, va_list ap);
void	handle_cases(char *s, t_node *node, va_list ap);
void	handle_zero(t_node *node);
void	handle_asterisk(char *s, t_node *node, va_list ap);
void	handle_dot(t_node *node);
void	update_content(char *new_str, t_node *node);
void	handle_d(t_node *node, va_list ap);


#endif
