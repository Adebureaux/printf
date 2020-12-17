.PHONY: all clean fclean re bonus

CC = gcc
NAME = libftprintf.a
#REMMETTRE LE FLAG !!!
CFLAGS = -Wall -Wextra #-Werror
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
				srcs/ft_precision.c
OBJS = 			${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c ${INC} $< -o ${<:.c=.o}

${NAME}: ${LIBFT} ${OBJS}
	ar rc ${NAME} ${OBJS} $(shell find libft -name '*.o')
	ranlib ${NAME}

${LIBFT}:
	@make all -C libft

all: ${NAME}

out: ${LIBFT}
	${CC} -g -fsanitize=address,undefined ${INC} ${LIBFT} ${CFLAGS} main.c ${SRCS}
	rm -rf a.out.dSYM
	./a.out

clean:
	rm -f ${OBJS}

fclean: clean
	@make clean -C libft
	rm -f ${NAME}
	rm -f ${LIBFT}
	rm -f a.out

re: fclean all
