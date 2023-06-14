/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:19:06 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/14 11:03:30 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	red_cross(t_vars *data)
{
	free_all(data);
	//system("leaks cub3D");
	exit(0);
	return (0);
}

int	key_press(int keycode, t_vars *data)
{
	if (keycode == KEY_W)
		data->keys.key_w = DOWN;
	else if (keycode == KEY_S)
		data->keys.key_s = DOWN;
	else if (keycode == KEY_A)
		data->keys.key_a = DOWN;
	else if (keycode == KEY_D)
		data->keys.key_d = DOWN;
	else if (keycode == SHIFT_LEFT)
		data->keys.shift_left = DOWN;
	else if (keycode == CTRL_LEFT)
		data->keys.ctrl_left = DOWN;
	else if (keycode == ARROW_LEFT)
		data->keys.arrow_left = DOWN;
	else if (keycode == ARROW_RIGHT)
		data->keys.arrow_right = DOWN;
	return (0);
}

int	key_release(int keycode, t_vars *data)
{
	if (keycode == KEY_W)
		data->keys.key_w = UP;
	else if (keycode == KEY_S)
		data->keys.key_s = UP;
	else if (keycode == KEY_A)
		data->keys.key_a = UP;
	else if (keycode == KEY_D)
		data->keys.key_d = UP;
	else if (keycode == ARROW_LEFT)
		data->keys.arrow_left = UP;
	else if (keycode == ARROW_RIGHT)
		data->keys.arrow_right = UP;
	else if (keycode == SHIFT_LEFT)
		data->keys.shift_left = UP;
	else if (keycode == CTRL_LEFT)
		data->keys.ctrl_left = UP;
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		red_cross(data);
	}
	return (0);
}

void	key_handler(t_vars *data)
{
	static double	angle = M_PI / 120;
	t_keys			*keys;

	keys = &data->keys;
	if (keys->ctrl_left == DOWN)
		data->player_speed = SPEED_WALK;
	else if (keys->shift_left == DOWN)
		data->player_speed = SPEED_SPRINT;
	else
		data->player_speed = SPEED_NORMAL;
	if (keys->key_w == DOWN)
		move_straight(data, data->player_speed);
	if (keys->key_s == DOWN)
		move_straight(data, -data->player_speed);
	if (keys->key_a == DOWN)
		move_sideways(data, data->player_speed);
	if (keys->key_d == DOWN)
		move_sideways(data, -data->player_speed);
	if (keys->arrow_left == DOWN)
		rotate(data, angle);
	if (keys->arrow_right == DOWN)
		rotate(data, -angle);
}

int	mouse_hook(int x, int y, t_vars *data)
{
	static int		x_mid = WINDOW_WIDTH / 2;
	static int		y_mid = WINDOW_HEIGHT / 2;
	static double	angle = M_PI / 90;

	(void)y;
	if (x > x_mid)
		rotate(data, -angle);
	else if (x < x_mid)
		rotate(data, angle);
	mlx_mouse_move(data->win, x_mid, y_mid);
	return (0);
}
