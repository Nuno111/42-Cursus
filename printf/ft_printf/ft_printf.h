#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

typedef struct		s_node
{
	char			*s;
	char			*buf;
    char            *new;
	size_t			i;
	size_t			len;
	long			prec_len;
	long			width_len;
    bool            left_align;
    bool            has_prec;
    bool            has_width;
    bool            from_arg;
    bool            pad_is_zero;
	bool			done;
	bool			can_trunc;
	bool			is_neg;
	va_list			ap;
	int				status;
}					t_node;

void	new_buff(t_node *n);
char	*str_join_free(char **beg, char **end);
void	handle_negative_wp(long *w_or_p_len, t_node *node);
char	*truncate_str(char *new_str, t_node *node);
char	*get_filler(char *new_str, long len, bool pad_is_zero);
void	handle_zero(t_node *node);
void	handle_asterisk(char *s, t_node *node, va_list ap);
void	handle_dot(t_node *node);
void	handle_hyphen(t_node *node);
int		handle_percent(char *s, char **to_print, va_list ap, int index);
void	handle_types(t_node *n);
void	handle_cases(t_node *n);
int		manage_node( char *s, char **to_print, va_list ap, int i);
int		ft_printf(const char *s, ...);
void	update_padding(char *s, t_node *node, va_list ap, long *w_or_l, bool from_arg);
void	handle_d(t_node *node, va_list ap);
void	handle_c(t_node *node, va_list ap);


#endif
