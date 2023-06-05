CFILES	= 	\
			main.c \
			hooks.c \
			utils_free.c \
			render_frame.c \
			get_color.c
			
SRCS 	= $(addprefix src/, ${CFILES})

OBJS	= ${SRCS:.c=.o}

NAME	= cub3D

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address

${NAME}:	${OBJS}
			${MAKE} -C libft
			${MAKE} -C mlx
			cp mlx/libmlx.dylib .
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a libmlx.dylib

all:		${NAME}

bonus:		${NAME}

clean:
			${RM} ${OBJS} ${bOBJS}
			$(MAKE) clean -C libft
			$(MAKE) clean -C mlx

fclean:		clean
			${RM} ${NAME}
			$(MAKE) fclean -C libft
			${RM} libmlx.dylib

re:			fclean all

.PHONY:		all bonus clean fclean re