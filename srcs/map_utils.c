/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:48:02 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/15 15:36:05 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	line_content(char *ret)
{
	int	i;

	i = 0;
	while (ret[i] && (ret[i] == 9 || (ret[i] >= 11 && ret[i] <= 13)
			|| ret[i] == ' '))
		i++;
	if (!ret[i])
		return (1);
	return (0);
}

int	is_space(char c)
{
	// if (!c)
	// 	error_msg("Map error\n");
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
		error_msg("Can't open the input file\n");
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
		if (!line_content(ret) && *count == 6)
			data->count_map++;
		if (line_content_map(ret) && *count != 6)
			error_msg("Map error\n");
	}
}