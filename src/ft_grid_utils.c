/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:45:33 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/02/16 13:52:42 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_gridadd_right(t_point **grid, t_point *new,
			t_point **last_right, t_point **last_down)
{
	if (*grid == NULL)
	{
		*grid = new;
		*last_right = new;
		*last_down = new;
		return ;
	}
	if (!new)
		return ;
	(*last_right)->next_right = new;
	*last_right = new;
}

void	ft_gridadd_down(t_point **grid, t_point *new,
			t_point **last_right, t_point **last_down)
{
	if (*grid == NULL)
	{
		*grid = new;
		*last_right = new;
		*last_down = new;
		return ;
	}
	if (!new)
		return ;
	(*last_down)->next_down = new;
	*last_down = new;
	*last_right = new;
}

int	ft_gridsize_horizontal(t_point *point)
{
	int		size;
	t_point	*temp;

	if (!point)
		return (0);
	size = 1;
	temp = point;
	while (temp->next_right)
	{
		size++;
		temp = temp->next_right;
	}
	return (size);
}

int	ft_gridsize_vertical(t_point *point)
{
	int		size;
	t_point	*temp;

	if (!point)
		return (0);
	size = 1;
	temp = point;
	while (temp->next_down)
	{
		size++;
		temp = temp->next_down;
	}
	return (size);
}

void	ft_free_grid(t_point **grid)
{
	t_point	*point;
	t_point	*temp_down;
	t_point	*temp_right;

	if (!grid)
		return ;
	if (!*grid)
	{
		free(grid);
		return ;
	}
	point = *grid;
	while (point)
	{
		temp_down = point->next_down;
		while (point)
		{
			temp_right = point->next_right;
			free(point);
			point = temp_right;
		}
		point = temp_down;
	}
	free(grid);
}
