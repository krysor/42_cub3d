/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:56:38 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/16 16:00:24 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

/* Allocate 2D array for the map */
void	allocate_map_utils(t_data *data, char **argv)
{
	data->map = malloc(sizeof(char *) * (data->len_map + 1));
	if (!data->map)
	{
		free_data(data);
		error_msg("Malloc error in allocate_map_utils\n");
	}
	open_file(data, argv);
	if (data->fd < 0)
	{
		free_data(data);
		error_msg("Open error in allocate_map_utils\n");
	}
}

void	replace_space_by_one(char *row)
{
	int	i;
	int	k;

	i = 0;
	while (row[i])
	{
		if (row[i] == '0' && row[i + 1] == ' ')
			return ;
		if (row[i] != '0' && row[i + 1] == ' ')
		{
			k = i + 1;
			while (row[k] == ' ')
				k++;
			if (row[k] == '0' || row[k] == '\0')
				return ;
			while (i < k)
			{	
				row[i] = '1';
				i++;
			}
		}
		else
			i++;
	}
}

/*
void	replace_space_by_one(char *row)
{
	int	i;
	int	k;

	if (row == NULL)
		return ;
	i = 0;
	while (row[i])
	{
		if (row[i] != '0' && row[i + 1] == ' ')
		{
			k = i + 1;
			while (row[k] == ' ')
				k++;
			if (row[k] == '0' || row[k] == '\0')
				return ;
			while (i < k)
			{	
				row[i] = '1';
				i++;
			}
		}
		// else if (row[i] == ' ' && row[i + 1] == '1')
		// 	row[i++] = '1';
		else
			i++;
	}
}*/

void	copy_line_to_map(t_data *data, char *ret, int *j_pnt, int *k_pnt)
{
	int	i_ret_last;
	int	j;

	i_ret_last = ft_strlen(ret) - 1;
	if (ret[i_ret_last] == '\n')
		ret[i_ret_last] = '\0';
	j = *j_pnt;
	data->map[j] = ft_strdup(ret);
	if (data->map[j] == NULL)
	{
		free(ret);
		free_data(data);
		error_msg("Malloc fail inside allocate_map\n");
	}
	(*j_pnt)++;
	(*k_pnt)--;
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
	k = data->len_map;
	allocate_map_utils(data, argv);
	ret = get_next_line(data->fd);
	while (ret)
	{
		if (i >= data->i_line_map_start && k > 0)
			copy_line_to_map(data, ret, &j, &k);
		i++;
		free(ret);
		ret = get_next_line(data->fd);
	}
	data->map[j] = NULL;
	close(data->fd);
}
