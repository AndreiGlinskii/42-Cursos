NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = ft_putchar.c ft_putstr.c ft_hex_pointer.c \
ft_putnbr.c ft_putnbr_base.c \
ft_printf.c 

INCLUDE = ft_printf.h

%.o: %.c $(INCLUDE)

	@${CC} ${CFLAGS} -c $< -o $@

OBJS = $(SRCS:.c=.o)

$(NAME):$(OBJS) $(INCLUDE)
	@${AR} ${NAME} ${OBJS}

all: $(NAME)

clean:
	@${RM} ${OBJS}

fclean:
	@${RM} ${OBJS}
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
