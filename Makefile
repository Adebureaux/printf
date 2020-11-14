.PHONY: all clean fclean re bonus

CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
SRCS =			srcs/ft_printf.c \
				srcs/utility_1.c \
				srcs/utility_2.c
OBJS = 			${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${LIBFT} ${OBJS}
	ar rc ${NAME} ${OBJS} $(shell find libft -name '*.o')
	ranlib ${NAME}

${LIBFT}:
	@make all -C libft

all: ${NAME}

out: ${LIBFT}
	${CC} ${LIBFT} ${CFLAGS} main.c ${SRCS}
	./a.out

clean:
	@make clean -C libft
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBFT}
	rm -f a.out

re: fclean all
