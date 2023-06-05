/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:42:06 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/05 15:24:32 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include "../mlx_linux/mlx.h"
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



//lode test//delete after
# define mapWidth 24
# define mapHeight 24



typedef struct s_data
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	
	void	*mlx;
	void	*win;
	void	*img1;
	void	*img2;
	int		img_next;

	void	*world_map;
	double	player_x;
	double	player_y;
	double	direction_x;
	double	direction_y;
	double	plane_x;
	double	plane_y;

	double	time;
	double	time_old;
}					t_data;

void		init_hooks(t_data *vars);
int			key_hook(int keycode, t_data *vars);
int			key_down(int keycode, t_data *vars);
int			red_cross(t_data *vars);

void		move_straight(t_data *data, double fraction);
void		move_sideways(t_data *data, double fraction);
void		rotate(t_data *data, double angle);

void		free_arr(char **arr);
void		free_all(t_data *vars);

int			render_frame(t_data *data);
void		my_pixel_put(t_data *data, int x, int y, int color);

#endif