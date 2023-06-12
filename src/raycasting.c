/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:16:18 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/12 11:59:07 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	dda(t_raycast *rc, int **world_map);
static void	draw_vertical_stripe(t_raycast *rc, t_data *data, int x);

void	raycasting(t_data *data)
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

static void	draw_vertical_stripe(t_raycast *rc, t_data *data, int x)
{
	double	perp_wall_distance;
	t_draw	draw;

	if (rc->side == 0)
		perp_wall_distance = rc->side_dist_x - rc->delta_dist_x;
	else
		perp_wall_distance = rc->side_dist_y - rc->delta_dist_y;
	draw.line_height = (int)(WINDOW_HEIGHT / perp_wall_distance);
	draw.start = (WINDOW_HEIGHT - draw.line_height) / 2;
	if (draw.start < 0)
		draw.start = 0;
	draw.end = (WINDOW_HEIGHT + draw.line_height) / 2;
	if (draw.end >= WINDOW_HEIGHT)
		draw.end = WINDOW_HEIGHT - 1;
		
	int color = RED;
	if (rc->side == 1)
		color /= 2;
	while (draw.start < draw.end)
		my_pixel_put(data, x, draw.start++, color);
	if (rc->side == 0)
		draw.wall_x = data->player_y + perp_wall_distance * rc->ray_dir_y;
	else
		draw.wall_x = data->player_x + perp_wall_distance * rc->ray_dir_x;
	draw.wall_x -= floor(draw.wall_x);
	draw.tex_x = data->tex_width - (int)(draw.wall_x * (double)data->tex_width) - 1;//width and height missing
	draw.step = (double)(data->tex_height / draw.line_height);//width and height missing
	
	draw.tex_pos = (draw.start + (draw.line_height - WINDOW_HEIGHT) / 2) * draw.step;
	while (draw.start < draw.end)
	{
		draw.tex_y = (int)draw.tex_pos & (data->tex_height - 1);//width and height missing
        draw.tex_pos += draw.step;
        my_pixel_put(data, x, draw.start++, *(mlx_get_data_addr(data->tex, &data->bits_per_pixel, &data->line_length, &data->endian) + data->tex_height * draw.tex_y + (int)draw.tex_x));
	}

	//void *img = mlx_xpm_file_to_image(vars.mlx, "xpm/1.xpm", &vars.tex_width, &vars.tex_height);
	// printf("img[%d][%d]: %u\n", 0, 0, *(mlx_get_data_addr(img, &vars.bits_per_pixel, &vars.line_length, &vars.endian)));
}
