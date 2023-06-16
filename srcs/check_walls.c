/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:00:35 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/16 16:44:45 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

/* Check if a '0' is not surrounded by a space or a non-existing texture */

void	check_gaps(char **map, int len_map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			//printf("bef or after seg 1: i: %d, j: %d\n", i, j);
			if (map[i][j] == '0')
			{
				// printf("bef or after seg 1: i: %d, j: %d\n", i, j);
				if (i > 0 && is_space(map[i - 1][j]))
					{error_msg("Map error: player can see undefined texture\n");
				
				printf("bef or after seg 2\n");}
				else if (i < len_map - 1 && is_space(map[i + 1][j]))
					{error_msg("Map error: player can see undefined texture\n");
				
				printf("bef or after seg 3\n");}
				else if (j > 0 && is_space(map[i][j - 1]))
					{error_msg("Map error: player can see undefined texture\n");
				
				printf("bef or after seg 4\n");}
				else if (j < (int)ft_strlen(map[i]) - 1
					&& is_space(map[i][j + 1]))
					{error_msg("Map error: player can see undefined texture\n");
				
				printf("bef or after seg 5\n");}
			}
		}
		j = -1;
	}
}

int	check_lastchar(char *str)
{
	int	i;

	i = (ft_strlen(str) - 1);
	if (str[i] != '1' && !is_space(str[i]))
		return (0);
	while (is_space(str[i]))
		i--;
	if (str[i] != '1')
		return (0);
	return (1);
}

/* Check if the 1st and the nth char of each line is a 1 */
void	check_delim_char(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = skip_space(map[i]);
		if (map[i][j] != '1' || !check_lastchar(map[i]))
			error_msg("Map is not surrounded by walls\n");
	}
}

/* Check if the 1st and the nth line of the map are 1 only */
void	check_delim_line(char **map, int len_map, t_data *data)
{
	int	i;

	i = -1;
	while (map[0][++i])
	{
		if (map[0][i] != '1' && !is_space(map[0][i]))
		{
			free_data(data);
			error_msg("Map error in first line\n");
		}
	}
	i = -1;
	while (map[len_map - 1][++i])
	{
		if (map[len_map - 1][i] != '1' && !is_space(map[len_map - 1][i]))
		{
			free_data(data);
			error_msg("Map error in last line\n");
		}
	}
}
