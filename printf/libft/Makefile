CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = libft.h

OPT = -c -g

LIBOPT = ar rcs

SRC = ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c\
ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putendl_fd.c\
ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memccpy.c ft_putnbr_fd.c ft_strlen.c\
ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c\
ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_lstadd_back.c\
ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c\
ft_lstnew.c ft_lstsize.c ft_strcat.c ft_isspace.c ft_strnew.c\
ft_freearrays.c ft_strchrindex.c ft_putchar.c ft_putnbr.c

NAME = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c $(LIB)
	$(CC) $(OPT) $(CFLAGS) $<

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all

.PHONY: all clean fclean re
