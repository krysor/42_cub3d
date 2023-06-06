/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:16:18 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/06 11:53:31 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	dda(t_raycast *rc, char **world_map);

void	raycasting(t_data *data)
{
	t_raycast	raycast;
	int			x;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		raycast.camera_x = 2 * x / WINDOW_WIDTH - 1;
		init_raycast(&raycast, data);
		dda(&raycast, *(char ***)data->world_map);
	}
}

static void	dda(t_raycast *rc, char **world_map)
{
	while (rc->hit == 0)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (world_map[rc->map_x][rc->map_y] > 0)
			rc->hit = 1;
	}
}
