CFILES	= 	\
			main.c \
			init_vars.c \
			hooks.c \
			move.c \
			utils_free.c \
			render_frame.c \
			raycasting.c \
			init_raycast.c
			
SRCS 	= $(addprefix src/, ${CFILES})

OBJS	= ${SRCS:.c=.o}

NAME	= cub3D

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -Os -O2 -O3 -fsanitize=address

MLX		= -framework OpenGL -framework AppKit

${NAME}:	${OBJS}
			${MAKE} -C libft
			${MAKE} -C mlx_opengl 
			${CC} ${CFLAGS} ${MLX} -o ${NAME} ${OBJS} libft/libft.a mlx_opengl/libmlx.a

all:		${NAME}

bonus:		${NAME}

clean:
			${RM} ${OBJS} ${bOBJS}
			$(MAKE) clean -C libft
			$(MAKE) clean -C mlx_opengl

fclean:		clean
			${RM} ${NAME}
			$(MAKE) fclean -C libft

re:			fclean all

.PHONY:		all bonus clean fclean re