/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:52:31 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/05/30 16:35:24 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_vars(t_data *data);

int	main(int argc, char *argv[])
{
	t_data	vars;

	(void)argv;
	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	init_vars(&vars);
	init_hooks(&vars);
	mlx_loop(vars.mlx);
	free_all(&vars);
	return (0);
}

static void	init_vars(t_data *data)
{
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
	data->scale = 1;
	data->x_mid = WINDOW_WIDTH / 2;
	data->y_mid = WINDOW_HEIGHT / 2;
	data->i_img = 0;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	data->img1 = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img2 = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
