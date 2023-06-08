/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:19:06 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/08 09:51:09 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#include <stdio.h>
int	mouse_movement(int x, int y, t_data *vars)
{
	static int	x_old = 0;
	//static int	x_mid = WINDOW_WIDTH / 2;
	//static int	y_mid = WINDOW_HEIGHT / 2;

	// printf("x: %d\n", x);
	// printf("y: %d\n", y);

	(void)y;
	//mlx_mouse_hide(vars->mlx, vars->win);
	if (x > x_old)
		rotate(vars, -M_PI / 90);
	else if (x < x_old)
		rotate(vars, M_PI / 90);
	x_old = x;
	// if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
	// 	mlx_mouse_move(vars->mlx, vars->win, x_mid, y_mid);
	return (0);
}


void	init_hooks(t_data *vars)
{
	mlx_mouse_hide(vars->mlx, vars->win);
	
	mlx_hook(vars->win, ON_DESTROY, NO_EVENT_MASK, red_cross, vars);
	mlx_hook(vars->win, ON_KEYDOWN, NO_EVENT_MASK, key_down, vars);

	mlx_hook(vars->win, 6, 0, mouse_movement, vars);
	//mlx_mouse_hook(vars->win, mouse_movement, vars);
	
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop_hook(vars->mlx, render_frame, vars);
}



int	key_hook(int keycode, t_data *vars)
{
	if (keycode == KEY_ESC)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	red_cross(t_data *vars)
{
	free_all(vars);
	exit(0);
	return (0);
}

int	key_down(int keycode, t_data *vars)
{
	if (keycode == KEY_W)
		move_straight(vars, 0.1);
	else if (keycode == KEY_S)
		move_straight(vars, -0.1);
	else if (keycode == KEY_A)
		move_sideways(vars, 0.1);
	else if (keycode == KEY_D)
		move_sideways(vars, -0.1);
	else if (keycode == ARROW_LEFT)
		rotate(vars, M_PI / 60);
	else if (keycode == ARROW_RIGHT)
		rotate(vars, -M_PI / 60);
	return (0);
}
