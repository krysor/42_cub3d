/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:56:38 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/07 15:09:57 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

/* Allocate 2D array for the map */
void	allocate_map_utils(t_data *data, char **argv)
{
	data->map = malloc(sizeof(char *) * (data->count_map + 1));
	if (!data->map)
		error_msg("Malloc error\n");
	open_file(data, argv);
	if (data->fd < 0)
		error_msg("Open error\n");
}

/* Read the file with gnl & dup the map in the 2D array */
void	allocate_map(t_data *data, char **argv)
{
	char	*ret;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = data->count_map;
	allocate_map_utils(data, argv);
	ret = get_next_line(data->fd);
	while (ret)
	{
		if (i >= data->count_file && k)
		{
			data->map[j++] = ft_strdup(ret);
			k--;
		}
		i++;
		free(ret);
		ret = get_next_line(data->fd);
	}
	data->map[j] = NULL;
	close(data->fd);
}
