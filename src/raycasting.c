/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:16:18 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/06 14:57:11 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	dda(t_raycast *rc, char **world_map);
static void	draw_vertical_stripe(t_raycast *rc, t_data *data, int x);

void	raycasting(t_data *data)
{
	t_raycast	raycast;
	int			x;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		init_raycast(&raycast, data, x);
		dda(&raycast, *(char ***)data->world_map);
		draw_vertical_stripe(&raycast, data, x);
	}
}

static void	dda(t_raycast *rc, char **world_map)
{
	(void)world_map;

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
		// if (world_map[rc->map_x][rc->map_y] > 0)
		// 	rc->hit = 1;
	}
}

static void	draw_vertical_stripe(t_raycast *rc, t_data *data, int x)
{
	double	perp_wall_distance;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;

	if (rc->side == 0)
		perp_wall_distance = rc->side_dist_x - rc->delta_dist_x;
	else
		perp_wall_distance = rc->side_dist_y - rc->delta_dist_y;
	line_height = (int)(WINDOW_HEIGHT / perp_wall_distance);
	draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
    draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_end >= WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;
	color = RED;
	if (rc->side == 1)
		color /= 2;
	while (draw_start < draw_end)
		my_pixel_put(data, x, draw_start++, color);
}