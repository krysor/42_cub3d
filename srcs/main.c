/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:52:31 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/19 16:47:17 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	init_hooks(t_vars *data);

void	ft_parsing(char **argv, t_data *data)
{
	check_extension(argv[1]);
	init_struct(data);
	browse_file(data, argv);
	allocate_map(data, argv);
	check_map(data->map, data);
}

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

void	equalize_length(char **map, t_data *data)
{
	size_t	len_max;
	int		i;
	char	*row_new;

	i = -1;
	len_max = -1;
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
		row_new = malloc(sizeof(char) * (len_max + 1));//add malloc protection
		if (row_new == NULL)
		{
			free_data(data);
			error_msg("Malloc fail insisde equalize_length\n");
		}
		ft_memset(row_new, '1', len_max);
		row_new[len_max] = '\0';
		ft_memcpy(row_new, map[i], ft_strlen(map[i]));
		free(map[i]);
		map[i] = row_new;
	}	
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		error_msg("Incorrect amount of arguments\n");
	ft_parsing(argv, &vars.data);

	
	spaces_to_ones(vars.data.map);
	equalize_length(vars.data.map, &vars.data);
	
	//add a function that
	//processes puts all variables into the cub3d struct
	//possibly reallocates the map
	//frees the parsing struct

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
