/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:42:27 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/09 17:24:33 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LNE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define ok 1
# define err -1
# define eof 0
# define BUFFER_SIZE 4

typedef struct                  s_list
{
        char                    *content;
        struct s_list   *next;
}                                               t_list;

t_list											*ft_lstnew(t_list **list, int fd, char *eofile);
char											*ft_strchr(const char *s, int c);
size_t											ft_strlcat(char *dst, const char *src, size_t size);
int												ft_helper(char **line, t_list *node, t_list **head);
size_t											ft_get_line_size(t_list *node);

#endif
