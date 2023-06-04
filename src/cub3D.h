/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:42:06 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/05/30 14:35:52 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include "../mlx/mlx.h"
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

typedef struct s_data
{
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
}					t_data;

void		init_hooks(t_data *vars);
int			key_hook(int keycode, t_data *vars);
int			key_down(int keycode, t_data *vars);
int			red_cross(t_data *vars);

void		free_arr(char **arr);
void		free_all(t_data *vars);

int			render_frame(t_data *data);
void		my_pixel_put(t_data *data, int x, int y, int color);

#endif