/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:52:31 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/20 14:21:38 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_arr(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(data->tex_parsing.texture[i]);
		i++;
	}
	free_arr(data->map);
	if (data->fd > -1)
		close(data->fd);
}

void	free_world_map(int **world_map)
{
	int	i;

	if (world_map == NULL)
		return ;
	i = -1;
	while (world_map[++i] != NULL)
		free(world_map[i]);
	free(world_map);
}

void	free_all(t_vars *vars)
{
	free_data(&vars->data);
	free_world_map(vars->world_map);
}
