NAME = libftprintf.a

SRC = $(wildcard ft_printf/*.c)

DST = $(SRC:.c=.o)

HEADER = ft_printf.h

DEP_LIB = libft/libft.a

all : $(NAME)

$(NAME) : $(DST)
	ar -rcs $@ $^

$(DST) : $(SRC) $(HEADER) $(DEP_LIB)
	gcc -g -Wall -Werror -Wextra $< $(DEP_LIB)

$(DEP_LIB) :
	cd libft && $(MAKE)

