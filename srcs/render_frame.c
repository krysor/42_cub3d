/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:07:17 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/19 14:29:41 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	flush_window(t_vars *data);

int	render_frame(t_vars *data)
{
	flush_window(data);
	key_handler(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

static void	flush_window(t_vars *data)
{
	int	x;
	int	y;
	int	y_mid;
	int	color_ceiling;
	int	color_floor;

	color_ceiling = data->color_ceiling;
	y = 0;
	y_mid = WINDOW_HEIGHT / 2;
	while (y < y_mid)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
			my_pixel_put(&data->img, x++, y, color_ceiling);
		y++;
	}
	color_floor = data->color_floor;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
			my_pixel_put(&data->img, x++, y, color_floor);
		y++;
	}
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
