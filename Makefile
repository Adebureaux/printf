.PHONY: all clean fclean re

CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
INC = -I./includes
SRCS =			srcs/ft_printf.c \
				srcs/ft_utility.c \
				srcs/display_c.c \
				srcs/display_s.c \
				srcs/display_p.c \
				srcs/display_d.c \
				srcs/display_u.c \
				srcs/display_x.c \
				srcs/display_ptf.c \
				srcs/display_pct.c \
				srcs/ft_precision.c \
				srcs/ft_hex.c
OBJS = 			${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c ${INC} $< -o ${<:.c=.o}

${NAME}: ${LIBFT} ${OBJS}
	ar rc ${NAME} ${OBJS} $(shell find libft -name '*.o')
	ranlib ${NAME}

${LIBFT}:
	@make all -C libft

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	@make clean -C libft
	rm -f ${NAME}
	rm -f ${LIBFT}

re: fclean all
