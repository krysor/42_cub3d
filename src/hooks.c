/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:19:06 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/08 14:56:04 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	red_cross(t_data *vars)
{
	free_all(vars);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_data *vars)
{
	if (keycode == KEY_W)
		vars->keys.key_w = DOWN;
	else if (keycode == KEY_S)
		vars->keys.key_s = DOWN;
	else if (keycode == KEY_A)
		vars->keys.key_a = DOWN;
	else if (keycode == KEY_D)
		vars->keys.key_d = DOWN;
	else if (keycode == SHIFT_LEFT)
		vars->keys.shift_left = DOWN;
	else if (keycode == CTRL_LEFT)
		vars->keys.ctrl_left = DOWN;
	else if (keycode == ARROW_LEFT)
		vars->keys.arrow_left = DOWN;
	else if (keycode == ARROW_RIGHT)
		vars->keys.arrow_right = DOWN;
	return (0);
}

int	key_release(int keycode, t_data *vars)
{
	if (keycode == KEY_W)
		vars->keys.key_w = UP;
	else if (keycode == KEY_S)
		vars->keys.key_s = UP;
	else if (keycode == KEY_A)
		vars->keys.key_a = UP;
	else if (keycode == KEY_D)
		vars->keys.key_d = UP;
	else if (keycode == ARROW_LEFT)
		vars->keys.arrow_left = UP;
	else if (keycode == ARROW_RIGHT)
		vars->keys.arrow_right = UP;
	else if (keycode == SHIFT_LEFT)
		vars->keys.shift_left = UP;
	else if (keycode == CTRL_LEFT)
		vars->keys.ctrl_left = UP;
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		red_cross(vars);//without this segfaults
	}
	return (0);
}

void	key_handler(t_data *vars)
{
	t_keys	*keys;

	keys = &vars->keys;
	if (keys->ctrl_left == DOWN)
		vars->player_speed = SPEED_WALK;
	else if (keys->shift_left == DOWN)
		vars->player_speed = SPEED_SPRINT;
	else
		vars->player_speed = SPEED_NORMAL;
	if (keys->key_w == DOWN)
		move_straight(vars, vars->player_speed);
	if (keys->key_s == DOWN)
		move_straight(vars, -vars->player_speed);
	if (keys->key_a == DOWN)
		move_sideways(vars, vars->player_speed);
	if (keys->key_d == DOWN)
		move_sideways(vars, -vars->player_speed);
	if (keys->arrow_left == DOWN)
		rotate(vars, M_PI / 120);
	if (keys->arrow_right == DOWN)
		rotate(vars, -M_PI / 120);
}

int	mouse_hook(int x, int y, t_data *vars)
{
	static int	x_mid = WINDOW_WIDTH / 2;
	static int	y_mid = WINDOW_HEIGHT / 2;

	(void)y;
	if (x > x_mid)
		rotate(vars, -M_PI / 90);
	else if (x < x_mid)
		rotate(vars, M_PI / 90);
	mlx_mouse_move(vars->win, x_mid, y_mid);
	return (0);
}
