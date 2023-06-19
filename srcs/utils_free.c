/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:52:31 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/19 14:16:50 by dsoroko          ###   ########.fr       */
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

void	free_all(t_vars *vars)
{
	free_data(&vars->data);
}
