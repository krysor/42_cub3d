/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:19:06 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/05/30 14:33:02 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_hooks(t_data *vars)
{
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, ON_DESTROY, NO_EVENT_MASK, red_cross, vars);
	mlx_hook(vars->win, ON_KEYDOWN, NO_EVENT_MASK, key_down, vars);
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
	if (keycode == ARROW_LEFT)
		vars->x_mid -= 5;
	else if (keycode == ARROW_RIGHT)
		vars->x_mid += 5;
	else if (keycode == KEY_W)
		vars->alpha -= M_PI * 5 / 180;
	else if (keycode == KEY_S)
		vars->alpha += M_PI * 5 / 180;
	else if (keycode == KEY_A)
		vars->beta += M_PI * 5 / 180;
	else if (keycode == KEY_D)
		vars->beta -= M_PI * 5 / 180;
	return (0);
}
