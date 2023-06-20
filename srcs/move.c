/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:26:13 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/20 15:01:42 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	move_straight(t_vars *d, double fraction)
{
	if (d->world_map[(int)(d->player_x + d->direction_x * fraction)]
		[(int)d->player_y] == 0)
		d->player_x += fraction * d->direction_x;
	if (d->world_map[(int)(d->player_x)]
		[(int)(d->player_y + d->direction_y * fraction)] == 0)
		d->player_y += fraction * d->direction_y;
}

void	move_sideways(t_vars *data, double fraction)
{
	double	cosa;
	double	sina;
	double	perpendicular_x;
	double	perpendicular_y;

	cosa = cos(M_PI / 2);
	sina = sin(M_PI / 2);
	perpendicular_x = cosa * data->direction_x - sina * data->direction_y;
	perpendicular_y = sina * data->direction_x + cosa * data->direction_y;
	if (data->world_map[(int)(data->player_x + perpendicular_x * fraction)]
		[(int)data->player_y] == 0)
		data->player_x += fraction * perpendicular_x;
	if (data->world_map[(int)(data->player_x)]
		[(int)(data->player_y + perpendicular_y * fraction)] == 0)
		data->player_y += fraction * perpendicular_y;
}

void	rotate(t_vars *data, double angle)
{
	double	cosa;
	double	sina;
	double	temp;

	cosa = cos(angle);
	sina = sin(angle);
	temp = data->direction_x;
	data->direction_x = cosa * data->direction_x - sina * data->direction_y;
	data->direction_y = sina * temp + cosa * data->direction_y;
	temp = data->plane_x;
	data->plane_x = cosa * data->plane_x - sina * data->plane_y;
	data->plane_y = sina * temp + cosa * data->plane_y;
}
