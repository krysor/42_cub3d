/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:07:17 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/02/16 13:55:25 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_flush_window(t_data *data);
static void	ft_draw_grid(t_data *data);

int	ft_render_frame(t_data *data)
{
	if (data->i_img == 0)
	{
		data->addr = mlx_get_data_addr(data->img1, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_flush_window(data);
		ft_draw_grid(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img1, 0, 0);
		data->i_img = 1;
	}
	else
	{
		data->addr = mlx_get_data_addr(data->img2, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_flush_window(data);
		ft_draw_grid(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img2, 0, 0);
		data->i_img = 0;
	}
	return (1);
}

static void	ft_flush_window(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
			my_pixel_put(data, x++, y, BLACK);
		y++;
	}	
}

static void	ft_draw_grid(t_data *data)
{
	t_point	*temp;

	temp = *(data->grid);
	while (temp)
	{
		ft_connect_alined_vertical(data, temp);
		temp = temp->next_right;
	}
	temp = *(data->grid);
	while (temp)
	{
		ft_connect_alined_horizontal(data, temp);
		temp = temp->next_down;
	}
}
