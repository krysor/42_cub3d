CFILES	= 	\
			main.c \
			ft_map_to_grid.c \
			ft_center_axes.c \
			get_next_line.c \
			ft_atoi.c \
			ft_point_utils.c \
			ft_grid_utils.c \
			ft_render_frame.c \
			ft_connect_points.c \
			ft_get_color.c \
			ft_hooks.c \
			
SRCS 	= $(addprefix src/, ${CFILES})

OBJS	= ${SRCS:.c=.o}

NAME	= fdf

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -O3

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