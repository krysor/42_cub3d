/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:11:10 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/20 16:20:32 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	init_mlx(t_vars *vars);
static void	init_textures(t_vars *vars);
static void	init_colors(t_vars *vars);

void	init_vars(t_vars *vars)
{
	init_mlx(vars);
	init_textures(vars);
	init_colors(vars);
	vars->keys.key_w = UP;
	vars->keys.key_a = UP;
	vars->keys.key_s = UP;
	vars->keys.key_d = UP;
	vars->keys.ctrl_left = UP;
	vars->keys.shift_left = UP;
	vars->keys.arrow_left = UP;
	vars->keys.arrow_right = UP;
	vars->player_speed = 0.05;
}

static void	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		handle_error(vars, "mlx_init failed");
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (vars->win == NULL)
		handle_error(vars, "mlx_new_window failed");
	vars->img.img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (vars->img.img == NULL)
		handle_error(vars, "mlx_new_image failed");
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	if (vars->img.addr == NULL)
		handle_error(vars, "mlx_get_data_addr failed");
}

static void	init_textures(t_vars *vars)
{
	int		i;
	t_img	*img;

	i = 0;
	while (i < 4)
	{
		vars->tex[i].path = vars->data.tex_parsing.texture[i];
		img = &vars->tex[i];
		img->img = mlx_xpm_file_to_image(vars->mlx,
				img->path, &img->width, &img->height);
		if (img->img == NULL || img->width == 0 || img->height == 0)
			handle_error(vars, "mlx_xpm_file_to_image failed with texture");
		img->addr = mlx_get_data_addr(img->img,
				&img->bits_per_pixel, &img->line_length, &img->endian);
		if (img->addr == NULL || img->bits_per_pixel == 0
			|| img->line_length == 0)
			handle_error(vars, "mlx_get_data_addr failed with texture");
		i++;
	}
}

static void	init_colors(t_vars *vars)
{
	vars->color_ceiling = vars->data.rgb[1].r << 16
		| vars->data.rgb[1].g << 8 | vars->data.rgb[1].b;
	vars->color_floor = vars->data.rgb[0].r << 16
		| vars->data.rgb[0].g << 8 | vars->data.rgb[0].b;
}
