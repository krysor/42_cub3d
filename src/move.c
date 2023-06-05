/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:26:13 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/05 14:23:49 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_straight(t_data *data, double fraction)
{
	data->player_x += fraction * data->direction_x;
	data->player_y += fraction * data->direction_y;
}

void	move_sideways(t_data *data, double fraction)
{
	double	cosa;
	double	sina;
	double	perpendicular_x;
	double	perpendicular_y;

	cosa = cos(M_PI / 2);
	sina = sin(M_PI / 2);
	perpendicular_x = cosa * data->direction_x - sina * data->direction_y;
	perpendicular_y = sina * data->direction_x + cosa * data->direction_y;
	data->player_x += fraction * perpendicular_x;
	data->player_y += fraction * perpendicular_y;
}

void	rotate(t_data *data, double angle)
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
