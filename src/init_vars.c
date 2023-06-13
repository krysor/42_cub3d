/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:11:10 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/13 10:20:24 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_mlx(t_data *data);
static void	init_textures(t_data *data);

void	init_vars(t_data *data)
{
	init_mlx(data);
	init_textures(data);
	data->keys.key_w = UP;
	data->keys.key_a = UP;
	data->keys.key_s = UP;
	data->keys.key_d = UP;
	data->keys.ctrl_left = UP;
	data->keys.shift_left = UP;
	data->keys.arrow_left = UP;
	data->keys.arrow_right = UP;
	data->player_x = 22;
	data->player_y = 12;
	data->player_speed = 0.05;
	data->direction_x = -1;
	data->direction_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
}

static void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		red_cross(data);
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (data->win == NULL)
		red_cross(data);
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (data->img == NULL)
		red_cross(data);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (data->addr == NULL)
		red_cross(data);
}

static void	init_textures(t_data *data)
{
	data->tex = mlx_xpm_file_to_image(data->mlx, "xpm/4.xpm", &data->tex_width, &data->tex_height);
	data->tex_addr = mlx_get_data_addr(data->tex, &data->tex_bits_per_pixel, &data->tex_line_length, &data->tex_endian);
}