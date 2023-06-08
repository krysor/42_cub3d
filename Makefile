CFILES	= 	\
			main.c \
			hooks.c \
			move.c \
			utils_free.c \
			render_frame.c \
			raycasting.c \
			init.c \
			get_color.c
			
SRCS 	= $(addprefix src/, ${CFILES})

OBJS	= ${SRCS:.c=.o}

NAME	= cub3D

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -Os -O2 -O3

MLX		= -framework OpenGL -framework AppKit  #$^ -o $@

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
			${RM} libmlx.a

re:			fclean all

.PHONY:		all bonus clean fclean re