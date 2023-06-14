/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:55:55 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/14 11:03:53 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	init_delta_dist(t_raycast *rc);
static void	init_step_and_side_dist(t_raycast *rc, t_vars *d);

void	init_raycast(t_raycast *rc, t_vars *data, int x)
{
	rc->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	rc->ray_dir_x = data->direction_x + data->plane_x * rc->camera_x;
	rc->ray_dir_y = data->direction_y + data->plane_y * rc->camera_x;
	rc->map_x = (int)data->player_x;
	rc->map_y = (int)data->player_y;
	rc->hit = 0;
	init_delta_dist(rc);
	init_step_and_side_dist(rc, data);
}

static void	init_delta_dist(t_raycast *rc)
{
	if (rc->ray_dir_x != 0)
		rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
	else
		rc->delta_dist_x = DBL_MAX;
	if (rc->ray_dir_y != 0)
		rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
	else
		rc->delta_dist_y = DBL_MAX;
}

static void	init_step_and_side_dist(t_raycast *rc, t_vars *d)
{
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (d->player_x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 - d->player_x) * rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (d->player_y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 - d->player_y) * rc->delta_dist_y;
	}
}
