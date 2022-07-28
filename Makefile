SRCS	=	ft_printf.c	ft_itoa_unsigned.c	ft_itoa_hex.c	ft_itoa_ptr.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a
LIBFT	= libft.a
LIBDIR	= ./libft

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I${LIBDIR}
RM		= rm -f

${NAME}:	${LIBFT} ${OBJS}
			cp ${LIBDIR}/${LIBFT} ${NAME}
			ar -rcs ${NAME} ${OBJS}

${LIBFT}:
			make -C ${LIBDIR}
			
.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C ${LIBDIR}

fclean:		clean
			${RM} ${NAME}
			make fclean -C ${LIBDIR}

re:			fclean all

.PHONY:		all clean fclean re