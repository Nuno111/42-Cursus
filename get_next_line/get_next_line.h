/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:42:27 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/07 17:26:17 by ngregori         ###   ########.fr       */
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

# define BUFFER_SIZE 16

typedef struct                  s_list
{
        char                    *content;
		size_t					*bytes_read;
        struct s_list   *next;
}                                               t_list;



int get_next_line(int fd, char **line);

#endif
