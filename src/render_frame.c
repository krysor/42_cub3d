/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:07:17 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/05 11:11:04 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_flush_window(t_data *data);

int	render_frame(t_data *data)
{
	if (data->i_img == 1)
	{
		data->addr = mlx_get_data_addr(data->img1, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_flush_window(data);
		//ft_draw_grid(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img1, 0, 0);
		data->i_img = 2;
	}
	else
	{
		data->addr = mlx_get_data_addr(data->img2, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_flush_window(data);
		//ft_draw_grid(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img2, 0, 0);
		data->i_img = 1;
	}
	return (0);
}

static void	ft_flush_window(t_data *data)
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

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

