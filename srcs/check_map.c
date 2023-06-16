/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:57:05 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/16 16:47:52 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	line_is_map(char *ret)
{
	int	i;

	i = 0;
	while (ret[i] && (ret[i] == 9 || (ret[i] >= 11 && ret[i] <= 13)
			|| ret[i] == ' '))
			i++;
	if (ret[i] == '1' || ret[i] == '0')
		return (1);
	return (0);
}

void	check_wrong_char(char **map, int len_map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (i < len_map - 1 && map[++i])
	{
		while (map[i][++j])
		{
			if (!is_space(map[i][j]) && map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
					&& map[i][j] != 'W')
			{
				free_data(data);
				error_msg("Wrong char in map\n");	
			}
		}
		j = -1;
	}
}

void	check_dup_char(char **map, t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = -1;
	count = 0;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				count++;
		}
		j = -1;
	}
	if (count != 1)
	{
		free_data(data);
		error_msg("Incorrect number of players\n");
	}
}

void	check_empty_line(char **map, t_data *data)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (line_is_empty(map[i]))
		{
			free_data(data);
			error_msg("Empty line in map\n");
		}
		i++;
	}
}

void	check_map(char **map, t_data *data)
{
	check_wrong_char(map, data->len_map, data);
	check_dup_char(map, data);
	check_empty_line(map, data);
	check_delim_line(map, data->len_map, data);
	//FROM HERE
	check_delim_char(map);
	check_gaps(map, data->len_map);
}
