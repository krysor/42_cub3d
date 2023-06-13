/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:07:17 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/13 09:18:03 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	flush_window(t_data *data);

int	render_frame(t_data *data)
{
	flush_window(data);
	key_handler(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

static void	flush_window(t_data *data)
{
	int	x;
	int	y;
	int	y_mid;

	y = 0;
	y_mid = WINDOW_HEIGHT / 2;
	while (y < y_mid)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
			my_pixel_put(data, x++, y, WHITE);
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
			my_pixel_put(data, x++, y, BLACK);
		y++;
	}
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
	// 	return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
