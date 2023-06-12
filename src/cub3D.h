/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:42:06 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/12 16:43:58 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_opengl/mlx.h"
# include <stdbool.h>
# include <limits.h>
# include <math.h>
# include <float.h>

# include <stdio.h> //delete later

//buffer size inside the get_next_line function
# define BUFFER_SIZE	2000

//colors in hexadecimal
# define WHITE			0xffffff
# define BLACK			0x0
# define RED			0xff0000

//window size
# define WINDOW_WIDTH 	1280//1920//1280//2560//1600
# define WINDOW_HEIGHT	720//1080//720//1440//900

//keycode values on macOS
# define KEY_W 			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D 			2
# define KEY_ESC		53
# define ARROW_LEFT		123
# define ARROW_RIGHT	124
# define CTRL_LEFT		256
# define SHIFT_LEFT		257

//mlx keyhook event macros
# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEMOVE	6
# define ON_DESTROY		17
# define NO_EVENT_MASK	0L

# define UP				0
# define DOWN			1

# define SPEED_WALK		0.01
# define SPEED_NORMAL	0.05
# define SPEED_SPRINT	0.10

//lode test//delete after
# define mapWidth 24
# define mapHeight 24

typedef struct s_keys
{
	int		arrow_left;
	int		arrow_right;
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		shift_left;
	int		ctrl_left;
}				t_keys;

typedef struct s_data
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	*mlx;
	void	*win;
	void	*img;

	t_keys	keys;
	double	player_speed;

	void	*world_map;
	double	player_x;
	double	player_y;
	double	direction_x;
	double	direction_y;
	double	plane_x;
	double	plane_y;

	void	*tex;
	int		tex_width;
	int		tex_height;

	char	*tex_addr;
	int		tex_bits_per_pixel;
	int		tex_line_length;
	int		tex_endian;
}					t_data;

typedef struct s_raycast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	int		map_x;
	int		map_y;

	double	delta_dist_x;
	double	delta_dist_y;

	double	step_x;
	double	step_y;
	double	side_dist_x;
	double	side_dist_y;

	int		hit;
	int		side;
}					t_raycast;

typedef struct s_draw
{
	int		line_height;
	int		start;
	int		end;

	double	wall_x;
	double	tex_x;

	double	step;
	double	tex_pos;

	int		tex_y;
}					t_draw;

void		init_vars(t_data *data);

void		init_hooks(t_data *vars);
int			red_cross(t_data *vars);
int			key_press(int keycode, t_data *vars);
int			key_release(int keycode, t_data *vars);
int			mouse_hook(int x, int y, t_data *vars);

void		move_straight(t_data *data, double fraction);
void		move_sideways(t_data *data, double fraction);
void		rotate(t_data *data, double angle);

int			render_frame(t_data *data);
void		key_handler(t_data *vars);
void		raycasting(t_data *data);
void		init_raycast(t_raycast *rc, t_data *data, int x);
void		my_pixel_put(t_data *data, int x, int y, int color);

void		free_arr(char **arr);
void		free_all(t_data *vars);

#endif