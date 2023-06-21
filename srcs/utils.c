/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:54:22 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/21 08:55:30 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_alloc(t_data *data)
{
	free_split(data->map);
	free(data->tex_parsing.texture);
}

void	copy_map(char **map, int **world_map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			world_map[j][i] = map[i][j] - '0';
	}
}

int	**translate_and_rotate(char **map, t_vars *vars)
{
	int	**world_map;
	int	i;

	vars->nb_rows = ft_strlen(map[0]);
	world_map = calloc(vars->nb_rows + 1, sizeof(int *));
	if (world_map == NULL)
		free_all(vars);
	if (world_map == NULL)
		error_msg("malloc fail inside translate_and_rotate\n");
	i = -1;
	while (map[++i])
		;
	vars->nb_columns = i;
	i = -1;
	while (++i < vars->nb_rows)
	{
		world_map[i] = calloc(vars->nb_columns, sizeof(int));
		if (world_map[i] == NULL)
		{
			free_all(vars);
			error_msg("malloc fail inside translate_and_rotate\n");
		}
	}
	copy_map(map, world_map);
	return (world_map);
}
