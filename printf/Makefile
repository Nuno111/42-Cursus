NAME = libftprintf.a

HEADER = ft_printf/ft_printf.h

DEP_HEADER = libft/libft.h

CC = gcc

CFLAGS =  -c -g -Wall -Werror -Wextra

LIB_FLAGS = -rcs

SRC = $(wildcard ft_printf/*.c)

DST = $(SRC:.c=.o)

DEP_SRC = $(wildcard libft/*.c)

DEP_DST = $(DEP_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(DST) $(DEP_DST)
	ar $(LIB_FLAGS) $@ $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

libft/%.o : libft/%.c $(DEP_HEADER)
	$(CC) $(CFLAGS) $< -o $@
