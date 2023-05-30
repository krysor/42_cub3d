/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:42:06 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/02/17 10:39:28 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2000
# endif

# ifndef WHITE
#  define WHITE 0xffffff
# endif

# ifndef BLACK
#  define BLACK 0x0
# endif

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1280
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 720
# endif

# ifndef ARROW_LEFT
#  define ARROW_LEFT 123
# endif

# ifndef ARROW_RIGHT
#  define ARROW_RIGHT 124
# endif

# ifndef ARROW_UP
#  define ARROW_UP 125
# endif

# ifndef ARROW_DOWN
#  define ARROW_DOWN 126
# endif

# ifndef KEY_MINUS
#  define KEY_MINUS 78
# endif

# ifndef KEY_PLUS
#  define KEY_PLUS 69
# endif

# ifndef ESC
#  define ESC 53
# endif

# ifndef KEY_A
#  define KEY_A 0
# endif

# ifndef KEY_S
#  define KEY_S 1
# endif

# ifndef KEY_D
#  define KEY_D 2
# endif

# ifndef KEY_Q
#  define KEY_Q 12
# endif

# ifndef KEY_W
#  define KEY_W 13
# endif

# ifndef KEY_E
#  define KEY_E 14
# endif

# ifndef KEY_I
#  define KEY_I 34
# endif

# ifndef KEY_F
#  define KEY_F 3
# endif

# ifndef ON_KEYDOWN
#  define ON_KEYDOWN 2
# endif

# ifndef ON_DESTROY
#  define ON_DESTROY 17
# endif

# ifndef NO_EVENT_MASK
#  define NO_EVENT_MASK 0L
# endif

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
	struct s_point	*next_right;
	struct s_point	*next_down;
}					t_point;

typedef struct s_data
{
	t_point	**grid;

	double	alpha;
	double	beta;
	double	gamma;
	double	scale;
	int		x_mid;
	int		y_mid;
	int		i_img;

	void	*mlx;
	void	*win;
	void	*img1;
	void	*img2;

	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		pixels_total;
	int		pixels_left;
}					t_data;

void		ft_free_all(t_data *vars);

t_point		**ft_map_to_grid(char *map, t_point **grid);
char		*get_next_line(int fd);
void		ft_free_arr(char **arr);
long int	ft_atoli(const char *nptr);
long int	ft_hatoli(char *str);
void		ft_center_axes(t_point **grid);

void		ft_gridadd_right(t_point **grid, t_point *new,
				t_point **last_right, t_point **last_down);
void		ft_gridadd_down(t_point **grid, t_point *new,
				t_point **last_right, t_point **last_down);
int			ft_gridsize_horizontal(t_point *point);
int			ft_gridsize_vertical(t_point *point);
void		ft_free_grid(t_point **grid);

t_point		*ft_pointnew(char *str, int x);
void		ft_copy_point(t_point *src, t_point *dst);
void		ft_scale_point(t_point *p, double factor);
void		ft_rotate_point(t_point *p, double a, double b, double g);

int			ft_render_frame(t_data *data);
void		ft_connect_alined_horizontal(t_data *data, t_point *p);
void		ft_connect_alined_vertical(t_data *data, t_point *p);
int			ft_get_color(t_data *data, t_point *p1, t_point *p2);
void		my_pixel_put(t_data *data, int x, int y, int color);

int			ft_key_hook(int keycode, t_data *vars);
int			ft_key_down(int keycode, t_data *vars);
int			ft_red_cross(t_data *vars);

#endif