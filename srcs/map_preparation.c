/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_preparation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:05:10 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/20 15:33:28 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
				vars->player_x = j + 0.5;
				vars->player_y = i + 0.5;
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
		equalize_line(map, data, len_max, i);
	}
}

void	equalize_line(char **map, t_data *data, int len_max, int i)
{
	char	*row_new;

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
