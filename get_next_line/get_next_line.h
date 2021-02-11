/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:42:27 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/11 16:43:56 by ngregori         ###   ########.fr       */
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
# define BUFFER_SIZE 100
# define MAX_FD 1025

size_t	ft_strlen(const char *s);
int		read_file(int fd, char **fd_num, char *eofile);
int		update_line(int fd, char **fd_num, char **line);
char    *ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);

#endif
