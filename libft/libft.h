/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:51:15 by ngregori          #+#    #+#             */
/*   Updated: 2021/02/13 23:27:45 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_list
{
	void			*content;
	struct s_list	*next;
}						t_list;

int     				ft_strchrindex(const char *s, int c);
void					ft_freearrays(char **array);
char    				*ft_strnew(size_t size);
char					*ft_itoa(int n);
char					*ft_strdup(const char *s);
char					*ft_strchr(const char *s, int c);
char					*ft_strcat(char *dest, char *src);
char					*ft_strrchr(const char *s, int c);
char					**ft_split(char const *s, char c);
char					*ft_strtrim(char const *s1, char const *set);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
char					*ft_substr(char const *s,
						unsigned int start, size_t len);
char					*ft_strnstr(const char *big,
						const char *little, size_t len);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_isprint(int c);
int						ft_isdigit(int c);
int						ft_isascii(int c);
int						ft_isalpha(int c);
int						ft_isalnum(int c);
int						ft_isspace(int c);
int						ft_lstsize(t_list *lst);
int						ft_atoi(const char *nptr);
int						ft_strncmp(char *s1, char *s2, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					ft_putstr_fd(char *s, int fd);
void					ft_putchar_fd(char c, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putnbr(int nb);
void					ft_putendl_fd(char *s, int fd);
void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *s, int c, size_t n);
void					*ft_calloc(size_t nmemb, size_t size);
void					*ft_calloc(size_t nmemb, size_t size);
void					ft_lstiter(t_list *lst, void (*f)(void *));
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstadd_front(t_list **lst, t_list *new);
void					*ft_memchr(const void *s, int c, size_t n);
void					ft_lstclear(t_list **lst, void (*del)(void*));
void					ft_lstdelone(t_list *lst, void (*del)(void*));
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memccpy(void *dest, const void *src,
						int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
size_t					ft_strlen(const char *s);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
t_list					*ft_lstlast(t_list *lst);
t_list					*ft_lstnew(void *content);
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
