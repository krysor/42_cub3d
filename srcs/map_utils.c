/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:48:02 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/20 15:00:11 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	line_is_empty(char *ret)
{
	int	i;

	i = 0;
	while (ret[i] && (ret[i] == 9 || (ret[i] >= 11 && ret[i] <= 13)
			|| ret[i] == ' ' || ret[i] == '\n'))
		i++;
	if (ret[i] == '\0')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == 9 || (c >= 11 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	skip_space(char *ret)
{
	int	i;

	i = 0;
	while (ret[i] && is_space(ret[i]))
		i++;
	return (i);
}

void	open_file(t_data *data, char **argv)
{
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
	{
		free_data(data);
		error_msg("Can't open the input file\n");
	}
}

void	browse_map_cond(char *ret, t_data *data, int *count)
{
	while (ret && is_space(*ret))
		ret++;
	if (!ft_strncmp(ret, "NO", 2))
		populate_texture(0, data, count, ret);
	else if (!ft_strncmp(ret, "SO", 2))
		populate_texture(1, data, count, ret);
	else if (!ft_strncmp(ret, "WE", 2))
		populate_texture(2, data, count, ret);
	else if (!ft_strncmp(ret, "EA", 2))
		populate_texture(3, data, count, ret);
	else if (!ft_strncmp(ret, "F", 1))
		populate_rgb(0, data, count, ret);
	else if (!ft_strncmp(ret, "C", 1))
		populate_rgb(1, data, count, ret);
	else
	{
		if (line_is_empty(ret) == 0 && *count == 6)
			data->len_map++;
		if (line_is_map(ret) && *count != 6)
		{
			free_data(data);
			error_msg("The map starts before the texture and color lines\n");
		}
	}
}
