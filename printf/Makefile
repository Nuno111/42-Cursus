NAME = libftprintf.a

SRC = $(wildcard ft_printf/*.c)

DST = $(SRC:.c=.o)

CC = gcc

CFLAGS =  -c -g -Wall -Werror -Wextra

LIB_FLAGS = -rcs

HEADER = ft_printf/ft_printf.h

LIB_DEP = libft/libft.a

A = $(wildcard libft/*.o)

all : $(LIB_DEP) $(NAME)

$(LIB_DEP) :
	$(MAKE) -C libft

$(NAME) : $(DST)
	ar $(LIB_FLAGS) $@ $^ $(A)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -I libft $< -o $@

.PHONY: $(LIB_DEP)
