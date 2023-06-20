/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:52:31 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/20 12:57:26 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	init_hooks(t_vars *data);

void	spaces_to_ones(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	save_direction(char direction, t_vars *vars)
{
	if (direction == 'N')
		return ;
	else if (direction == 'S')
		rotate(vars, M_PI);
	else if (direction == 'W')
		rotate(vars, M_PI / 2);
	else if (direction == 'E')
		rotate(vars, -M_PI / 2);
}

void	replace_position(char **map, t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				vars->player_x = j;
				vars->player_y = i;
				save_direction(map[i][j], vars);
				map[i][j] = '0';
			}
		}
		j = -1;
	}
}

void	equalize_length(char **map, t_data *data)
{
	size_t	len_max;
	int		i;
	char	*row_new;

	len_max = 0;
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > len_max)
			len_max = ft_strlen(map[i]);
	}
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) == len_max)
			continue ;
		row_new = calloc(len_max + 1, sizeof(char));
		if (row_new == NULL)
		{
			free_data(data);
			error_msg("malloc fail inside equalize_length\n");
		}
		ft_memset(row_new, '1', len_max);
		ft_memcpy(row_new, map[i], ft_strlen(map[i]));
		free(map[i]);
		map[i] = row_new;
	}
}

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

int	**translate_and_rotate(char **map, t_vars *vars)
{
	int	**world_map;
	int	i;

	vars->nb_columns = ft_strlen(map[0]);
	world_map = malloc((vars->nb_columns + 1) * sizeof(int *));
	if (world_map == NULL)
	{
		free_all(vars);
		error_msg("malloc fail inside translate_and_rotate\n");
	}
	i = -1;
	while (map[++i])
		;
	vars->nb_rows = i;
	world_map[i] = NULL;
	i = -1;
	while (++i < vars->nb_columns)
	{
		world_map[i] = malloc(vars->nb_rows * sizeof(int));
		if (world_map[i] == NULL)
		{
			free_all(vars);
			error_msg("malloc fail inside translate_and_rotate\n");
		}
	}
	return (world_map);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		error_msg("Incorrect amount of arguments\n");
	ft_parsing(argv, &vars.data, &vars);

	int	i = -1;
	while (vars.data.map[++i])
		printf("map[%2d]: %s\n", i, vars.data.map[i]);

	translate_and_rotate(vars.data.map, &vars);

	free_all(&vars);
	return (0);

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
