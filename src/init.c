/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:55:55 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/09 15:30:46 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_delta_dist(t_raycast *rc);
static void	init_step_and_side_dist(t_raycast *rc, t_data *d);

void	init_vars(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->keys.key_w = UP;
	data->keys.key_a = UP;
	data->keys.key_s = UP;
	data->keys.key_d = UP;
	data->keys.ctrl_left = UP;
	data->keys.shift_left = UP;
	data->keys.arrow_left = UP;
	data->keys.arrow_right = UP;
	data->player_x = 22;
	data->player_y = 12;
	data->player_speed = 0.05;
	data->direction_x = -1;
	data->direction_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	//add all textures initialisations
	data->tex = l
}

void	init_hooks(t_data *vars)
{
	mlx_mouse_hide(vars->mlx, vars->win);
	mlx_hook(vars->win, ON_DESTROY, NO_EVENT_MASK, red_cross, vars);
	mlx_hook(vars->win, ON_KEYDOWN, NO_EVENT_MASK, key_press, vars);
	mlx_hook(vars->win, ON_KEYUP, NO_EVENT_MASK, key_release, vars);
	mlx_hook(vars->win, ON_MOUSEMOVE, NO_EVENT_MASK, mouse_hook, vars);
	mlx_loop_hook(vars->mlx, render_frame, vars);
}

void	init_raycast(t_raycast *rc, t_data *data, int x)
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

static void	init_step_and_side_dist(t_raycast *rc, t_data *d)
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
