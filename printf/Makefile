NAME = libftprintf.a

SRC = $(wildcard ft_printf/*.c)

DST = $(SRC:.c=.o)

CC = gcc

CFLAGS =  -c -g -Wall -Werror -Wextra

LIB_FLAGS = -rcs

HEADER = ft_printf/ft_printf.h

LIB_DEP = libft/libft.a

all : $(CHECK_DEP) $(NAME)

$(CHECK_DEP) :
	$(MAKE) -C libft

$(NAME) : $(DST)
	ar $(LIB_FLAGS) $@ $^ $(LIB_DEP)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -o $@


