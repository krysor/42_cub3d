/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:52:31 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/20 15:39:26 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	init_hooks(t_vars *data);

void	ft_parsing(char **argv, t_data *data, t_vars *vars)
{
	check_extension(argv[1]);
	init_struct(data);
	browse_file(data, argv);
	allocate_map(data, argv);
	check_map(data->map, data);
	spaces_to_ones(data->map);
	equalize_length(data->map, data);
	replace_position(data->map, vars);
}

// void	copy_map(char **map, int **world_map)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (map[++i])
// 	{
// 		j = -1;
// 		while (map[i][++j])
// 			world_map[j][i] = map[i][j] - '0';
// 	}
// }

// int	**translate_and_rotate(char **map, t_vars *vars)
// {
// 	int	**world_map;
// 	int	i;

// 	vars->nb_rows = ft_strlen(map[0]);
// 	world_map = calloc(vars->nb_rows + 1, sizeof(int *));
// 	if (world_map == NULL)
// 	{
// 		free_all(vars);
// 		error_msg("malloc fail inside translate_and_rotate\n");
// 	}
// 	i = -1;
// 	while (map[++i])
// 		;
// 	vars->nb_columns = i;
// 	i = -1;
// 	while (++i < vars->nb_rows)
// 	{
// 		world_map[i] = calloc(vars->nb_columns, sizeof(int));
// 		if (world_map[i] == NULL)
// 			free_all(vars);
// 		if (world_map[i] == NULL)
// 			error_msg("malloc fail inside translate_and_rotate\n");
// 	}
// 	copy_map(map, world_map);
// 	return (world_map);
// }

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		error_msg("Incorrect amount of arguments\n");
	ft_parsing(argv, &vars.data, &vars);
	vars.world_map = translate_and_rotate(vars.data.map, &vars);
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
