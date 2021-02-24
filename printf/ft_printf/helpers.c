/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:57:00 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/24 23:42:01 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*get_filler(char *new_str, t_node *node, int *len)
{
	char	*filler;
	int		new_len;

	new_len = *len - ft_strlen(new_str);
	filler = malloc(sizeof(char) * new_len + 1);
	if (!filler)
		return (NULL);
	if (node->pad_is_zero)
		ft_memset(filler, '0', new_len);
	else
		ft_memset(filler, ' ', new_len);
	filler[new_len] = '\0';
	return (filler);
}

char	*truncate_str(char *new_str, t_node *node)
{
	char *new;

	new = ft_substr(new_str, 0, node->prec_len);
	free(new_str);
	return (new);
}

void	manage_padding(char *new_str, t_node *node)
{
	size_t	length;
	int		*wid_or_pre;
	char	*filler;
	char	*tmp;

	if (node->can_trunc && (int)ft_strlen(new_str) > node->prec_len)
		new_str = truncate_str(new_str, node);
	length = ft_strlen(new_str);
	if (node->prec_len > node->width_len)
	{
		wid_or_pre = &node->prec_len;
		node->pad_is_zero = TRUE;
	}
	else if (node->has_width)
		wid_or_pre = &node->width_len;
	filler = get_filler(new_str, node, wid_or_pre);
	if ((int)length > *wid_or_pre)
		node->content = new_str;
	else if (node->left_align)
		node->content = ft_strjoin(new_str, filler);
	else if (node->is_neg)
	{
		tmp = ft_strjoin("-", filler);
		node->content = ft_strjoin(tmp, new_str);
		free(tmp);
	}
	else
		node->content = new_str;
	free(filler);
	free(new_str);
}


void	update_content(char *new_str, t_node *node)
{
	if (node->has_prec || node->has_width)
		manage_padding(new_str, node);
	else if (node->can_trunc && (int)ft_strlen(new_str) < node->prec_len)
		new_str = truncate_str(new_str, node);
	else
		node->content = new_str;
}

int		manage_node(char *s, char **to_print, va_list ap, int i)
{
	t_node node;
	char *new_str;

	node.i = i;
	node.has_width = FALSE;
	node.has_prec = FALSE;
	node.pad_is_zero = FALSE;
	node.left_align = FALSE;
	node.from_arg = FALSE;
	node.done = FALSE;
	node.content = NULL;
	node.prec_len = 0;
	node.width_len = 0;
	while (node.done != TRUE)
		handle_cases(s, &node, ap);
	if (node.content)
	{
		new_str = ft_strjoin(*to_print, node.content);
		free(node.content);
		if (*to_print)
			free(*to_print);
		*to_print = new_str;
	}
	return (node.i);
}

int		iterate_string(char *s, char **to_print, va_list ap)
{
	int	i;
	int length;

	length = ft_strlen(s);
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			add_letter(s[i], to_print);
			i++;
		}
		else
			i = handle_percent(s, to_print, ap, i);
		if (i < 0)
			return (-1);
		else if (i > length)
			return (0);
	}
	return (0);
}

void	add_letter(char s, char **to_print)
{
	char *new;

	if (*to_print == NULL)
	{
		*to_print = ft_strdup("");
	}
	new = ft_strjoin_c(*to_print, s);
	free(*to_print);
	*to_print = new;
}

void	update_padding(char *s, t_node *node, va_list ap, int *w_or_p_len, bool from_arg)
{
	int i;
	char *str_len;

	if (!node->has_prec)
		node->has_width = TRUE;
	i = 0;
	if (from_arg)
		*w_or_p_len = va_arg(ap, int);
	else
	{
		i = 0;
		while (ft_isdigit(s[node->i + i]))
			i++;
		str_len = ft_substr(s, node->i, i);
		*w_or_p_len = ft_atoi(str_len);
		free(str_len);
		// need to add on types, if pane_len > 0 then node->has_pad = TRUE
		// depending on type
		node->i += i;
	}
	if (*w_or_p_len < 0)
	{
		if (!node->has_prec)
		{
			node->left_align = TRUE;
			*w_or_p_len *= -1;
		}
		else
		{
			node->has_prec = FALSE;
			*w_or_p_len = 0;
		}
	}
}
