/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:52:31 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/02/17 11:03:53 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_vars(t_data *data);

int	main(int argc, char *argv[])
{
	t_data	vars;

	if (argc != 2)
	{
		perror("Please provide exactly one map");
		return (1);
	}	
	vars.grid = ft_map_to_grid(argv[1], vars.grid);
	ft_init_vars(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	vars.img1 = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars.img2 = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_key_hook(vars.win, ft_key_hook, &vars);
	mlx_hook(vars.win, ON_DESTROY, NO_EVENT_MASK, ft_red_cross, &vars);
	mlx_hook(vars.win, ON_KEYDOWN, NO_EVENT_MASK, ft_key_down, &vars);
	mlx_loop_hook(vars.mlx, ft_render_frame, &vars);
	mlx_loop(vars.mlx);
	ft_free_all(&vars);
	return (0);
}

static void	ft_init_vars(t_data *data)
{
	data->alpha = asin(tan(M_PI / 6)) - M_PI / 2;
	data->beta = 0;
	data->gamma = 0;
	data->scale = 1;
	data->x_mid = WINDOW_WIDTH / 2;
	data->y_mid = WINDOW_HEIGHT / 2;
	data->i_img = 0;
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_free_all(t_data *vars)
{
	ft_free_grid(vars->grid);
	free(vars->img1);
	free(vars->img2);
}
