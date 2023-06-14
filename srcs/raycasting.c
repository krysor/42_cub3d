/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:16:18 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/14 11:04:14 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void		dda(t_raycast *rc, int **world_map);
static void		draw_vertical_stripe(t_raycast *rc, t_vars *data, int x);
static t_img	*get_texture(t_raycast *rc, t_vars *data);
static void		draw_init(t_raycast *rc, t_vars *data, t_draw *draw,
					t_img *tex);

void	raycasting(t_vars *data)
{
	t_raycast	raycast;
	int			x;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		init_raycast(&raycast, data, x);
		dda(&raycast, *(int ***)(data->world_map));
		draw_vertical_stripe(&raycast, data, x);
	}
}

static void	dda(t_raycast *rc, int **world_map)
{
	(void)world_map;
	int worldMap[mapWidth][mapHeight] =
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

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
		if (worldMap[rc->map_x][rc->map_y] > 0)
		 	rc->hit = 1;
		// if (world_map[rc->map_x][rc->map_y] > 0)
		//  	rc->hit = 1;
	}
}

static void	draw_vertical_stripe(t_raycast *rc, t_vars *data, int x)
{
	t_draw	draw;
	t_img	*texture;
	char	*address_texture;
	int		color;

	texture = get_texture(rc, data);
	if (texture == NULL)
		handle_error(data, "get_texture: no texture found");
	draw_init(rc, data, &draw, texture);
	while (draw.start < draw.end)
	{
		draw.tex_y = (int)draw.tex_pos;
		address_texture = texture->addr + draw.tex_y * texture->line_length
			+ draw.tex_x * (texture->bits_per_pixel / 8);
		color = *(unsigned int *)address_texture;
		my_pixel_put(&data->img, x, draw.start, color);
		draw.tex_pos += draw.step;
		draw.start++;
	}
}

static t_img	*get_texture(t_raycast *rc, t_vars *data)
{
	if (rc->side == 1 && rc->ray_dir_y > 0)
		return (&data->tex[0]);
	if (rc->side == 1 && rc->ray_dir_y < 0)
		return (&data->tex[1]);
	if (rc->side == 0 && rc->ray_dir_x > 0)
		return (&data->tex[2]);
	if (rc->side == 0 && rc->ray_dir_x < 0)
		return (&data->tex[3]);
	return (NULL);
}

static void	draw_init(t_raycast *rc, t_vars *data, t_draw *draw, t_img *tex)
{
	if (rc->side == 0)
		draw->perp_wall_distance = rc->side_dist_x - rc->delta_dist_x;
	else
		draw->perp_wall_distance = rc->side_dist_y - rc->delta_dist_y;
	draw->line_height = (int)(WINDOW_HEIGHT / draw->perp_wall_distance);
	draw->start = (WINDOW_HEIGHT - draw->line_height) / 2;
	if (draw->start < 0)
		draw->start = 0;
	draw->end = (WINDOW_HEIGHT + draw->line_height) / 2;
	if (draw->end >= WINDOW_HEIGHT)
		draw->end = WINDOW_HEIGHT - 1;
	if (rc->side == 0)
		draw->wall_x = data->player_y
			+ draw->perp_wall_distance * rc->ray_dir_y;
	else
		draw->wall_x = data->player_x
			+ draw->perp_wall_distance * rc->ray_dir_x;
	draw->wall_x -= floor(draw->wall_x);
	draw->tex_x = (int)(draw->wall_x * (double)tex->width);
	if ((rc->side == 0 && rc->ray_dir_x > 0)
		|| (rc->side == 1 && rc->ray_dir_y < 0)) 
		draw->tex_x = tex->width - draw->tex_x - 1;
	draw->step = 1.0 * tex->height / draw->line_height;
	draw->tex_pos = draw->step
		* (draw->start + (draw->line_height - WINDOW_HEIGHT) / 2);
}
