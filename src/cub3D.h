/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:42:06 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/05/30 14:18:31 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>

//buffer size inside the get_next_line function
# define BUFFER_SIZE	2000

//colors in hexadecimal
# define WHITE			0xffffff
# define BLACK			0x0

//window size
# define WINDOW_WIDTH 	1280
# define WINDOW_HEIGHT	720

//keycode values on macOS
# define ARROW_LEFT		123
# define ARROW_RIGHT	124

# define KEY_W 			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D 			2
# define KEY_ESC		53

//mlx keyhook event macros
# define ON_KEYDOWN		2
# define ON_DESTROY		17
# define NO_EVENT_MASK	0L

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