/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_center_axes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:14:53 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/02/16 12:32:01 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	**ft_set_y(t_point **grid);
static int		ft_get_z_middle(t_point	*point);

void	ft_center_axes(t_point **grid)
{
	int		x_middle;
	int		x_middle_temp;
	int		z_middle;
	t_point	*point;
	t_point	*temp_down;

	grid = ft_set_y(grid);
	point = *grid;
	x_middle = ft_gridsize_horizontal(point) / 2;
	z_middle = ft_get_z_middle(point);
	while (point)
	{
		temp_down = point->next_down;
		x_middle_temp = -x_middle;
		while (point)
		{
			point->x = x_middle_temp++;
			point->z -= z_middle;
			ft_scale_point(point, 20);
			ft_rotate_point(point, 0, 0, -M_PI / 4);
			point = point->next_right;
		}
		point = temp_down;
	}
}

static t_point	**ft_set_y(t_point **grid)
{
	t_point	*point;
	t_point	*temp_down;
	int		y_middle;

	if (!grid || !*grid)
		return (grid);
	y_middle = -ft_gridsize_vertical(*grid) / 2;
	point = *grid;
	while (point)
	{
		temp_down = point->next_down;
		while (point)
		{
			point->y = y_middle;
			point = point->next_right;
		}
		point = temp_down;
		y_middle++;
	}
	return (grid);
}

static int	ft_get_z_middle(t_point	*point)
{
	t_point	*temp;
	t_point	*temp_down;
	int		z_min;
	int		z_max;

	temp = point;
	z_min = temp->z;
	z_max = temp->z;
	while (temp)
	{
		temp_down = temp->next_down;
		while (temp)
		{
			if (temp->z < z_min)
				z_min = temp->z;
			if (temp->z > z_max)
				z_max = temp->z;
			temp = temp->next_right;
		}
		temp = temp_down;
	}
	return ((z_min - z_max) / 2);
}
