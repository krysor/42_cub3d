CFILES	= 	\
			main.c \
			init_vars.c \
			hooks.c \
			move.c \
			utils_free.c \
			render_frame.c \
			raycasting.c \
			init_raycast.c \
			get_next_line_utils.c\
			get_next_line.c\
			allocate_map.c\
			check_extension.c\
			check_map.c\
			check_walls.c\
			browse_file.c\
			init_struct.c\
			map_utils.c\
			utils.c
			
SRCS 	= $(addprefix srcs/, ${CFILES})

OBJS	= ${SRCS:.c=.o}

NAME	= cub3D

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address #-Os -O2 -O3 

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