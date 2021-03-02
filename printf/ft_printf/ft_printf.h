#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

typedef struct		s_node
{
	const	char			*s;
	char					*buf;
    char            		*new;
	char					type;
	size_t					buf_len;
	size_t					i;
	size_t					len;
	long					prec_len;
	long					width_len;
    bool					left_align;
    bool					has_prec;
    bool					has_width;
    bool					from_arg;
    bool					pad_is_zero;
	bool					done;
	bool					can_trunc;
	bool					is_neg;
	va_list					ap;
}					t_node;

void	handle_c(t_node *n);
void	new_buffer(t_node *n);
void	reset_and_free(t_node *n);
void	new_buff(t_node *n);
char	*str_join_free(char **beg, char **end);
void	handle_negative_wp(long *w_or_p_len, t_node *n);
char	*truncate_str(char *new_str, t_node *n);
char	*get_filler(char *new_str, long len, bool pad_is_zero);
void	handle_zero(t_node *n);
void	handle_asterisk(t_node *n);
void	handle_dot(t_node *n);
void	handle_hyphen(t_node *n);
void	handle_types(t_node *n);
void	handle_cases(t_node *n);
int		ft_printf(const char *s, ...);
void	update_padding(t_node *n, long *w_or_l, bool from_arg);
void	handle_d(t_node *n);


#endif
