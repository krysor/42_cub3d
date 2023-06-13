/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:11:10 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/13 13:39:12 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_mlx(t_data *data);
static void	init_textures(t_data *data);

void	init_data(t_data *data)
{
	init_mlx(data);

	data->tex[0].path = "xpm/1.xpm";
	data->tex[1].path = "xpm/2.xpm";
	data->tex[2].path = "xpm/3.xpm";
	data->tex[3].path = "xpm/4.xpm";

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
	// data->direction_x = -1;
	// data->direction_y = 0;
	// data->plane_x = 0;
	// data->plane_y = 0.66;
	data->direction_x = 0;
	data->direction_y = 1;
	data->plane_x = 0.66;
	data->plane_y = 0;
}

static void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		handle_error(data, "mlx_init failed");
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (data->win == NULL)
		handle_error(data, "mlx_new_window failed");
	data->img.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (data->img.img == NULL)
		handle_error(data, "mlx_new_image failed");
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	if (data->img.addr == NULL)
		handle_error(data, "mlx_get_data_addr failed");
}

static void	init_textures(t_data *data)
{
	int		i;
	t_img	*img;

	i = 0;
	while (i < 4)
	{
		img = &data->tex[i];
		img->img = mlx_xpm_file_to_image(data->mlx,
				img->path, &img->width, &img->height);
		if (img->img == NULL || img->width == 0 || img->height == 0)
			handle_error(data, "mlx_xpm_file_to_image failed with texture");
		img->addr = mlx_get_data_addr(img->img,
				&img->bits_per_pixel, &img->line_length, &img->endian);
		if (img->addr == NULL || img->bits_per_pixel == 0
			|| img->line_length == 0)
			handle_error(data, "mlx_get_data_addr failed with texture");
		i++;
	}
}
