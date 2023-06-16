/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:52:31 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/16 11:30:38 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	init_hooks(t_vars *data);

void ft_parsing(char **argv, t_data *data)
{
	check_extension(argv[1]);
	init_struct(data);
	browse_file(data, argv);

	// int	i = -1;
	// while (++i < 4)
	// 	printf("tex %d: %s\n", i, data->tex_parsing.texture[i]);

	// int i = -1;
	// while (++i < 2)
	// 	printf("rgb[%d]: %d, %d, %d\n", i, data->rgb[i].r, data->rgb[i].g, data->rgb[i].b);

	allocate_map(data, argv);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		error_msg("Incorrect amount of arguments\n");
	ft_parsing(argv, &vars.data);
	check_map(vars.data.map, &vars.data);

	// int	i = -1;
	// while (vars.data.map[++i])
	// 	printf("%s\n", vars.data.map[i]);

	int worldMap[mapWidth][mapHeight] =
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	vars.world_map = &worldMap;

	init_vars(&vars);
	init_hooks(&vars);
	mlx_loop(vars.mlx);
}

static void	init_hooks(t_vars *data)
{
	mlx_mouse_hide(data->mlx, data->win);
	mlx_hook(data->win, ON_DESTROY, NO_EVENT_MASK, red_cross, data);
	mlx_hook(data->win, ON_KEYDOWN, NO_EVENT_MASK, key_press, data);
	mlx_hook(data->win, ON_KEYUP, NO_EVENT_MASK, key_release, data);
	mlx_hook(data->win, ON_MOUSEMOVE, NO_EVENT_MASK, mouse_hook, data);
	mlx_loop_hook(data->mlx, render_frame, data);
}

void	handle_error(t_vars *data, char *error_message)
{
	if (error_message != NULL)
		printf("%s\n", error_message);
	free_all(data);
	exit(1);
}