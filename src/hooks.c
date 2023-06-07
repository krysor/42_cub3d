/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:19:06 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/07 12:04:41 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#include <stdio.h>
int	mouse_movement(int x, int y, t_data *vars)
{
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	
	mlx_mouse_hide(vars->mlx, vars->win);
	
	//(void)mousecode;
	(void)vars;
	return (0);
}


void	init_hooks(t_data *vars)
{
	mlx_hook(vars->win, ON_DESTROY, NO_EVENT_MASK, red_cross, vars);
	mlx_hook(vars->win, ON_KEYDOWN, NO_EVENT_MASK, key_down, vars);

	mlx_hook(vars->win, 0, 0, mouse_movement, vars);
	// //mlx_mouse_hook(vars->win, mouse_movement, vars);
	
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
