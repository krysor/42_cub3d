/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:19:06 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/02/17 10:11:43 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key_hook(int keycode, t_data *vars)
{
	if (keycode == ESC)
		mlx_destroy_window(vars->mlx, vars->win);
	else if (keycode == KEY_F)
	{
		vars->alpha = 0;
		vars->beta = 0;
		vars->gamma = M_PI / 4;
	}
	else if (keycode == KEY_I)
	{
		vars->alpha = asin(tan(M_PI / 6)) - M_PI / 2;
		vars->beta = 0;
		vars->gamma = 0;
	}
	return (0);
}

int	ft_red_cross(t_data *vars)
{
	ft_free_all(vars);
	exit(0);
	return (0);
}

int	ft_key_down(int keycode, t_data *vars)
{
	if (keycode == ARROW_UP)
		vars->y_mid += 5;
	else if (keycode == ARROW_DOWN)
		vars->y_mid -= 5;
	else if (keycode == ARROW_LEFT)
		vars->x_mid -= 5;
	else if (keycode == ARROW_RIGHT)
		vars->x_mid += 5;
	else if (keycode == KEY_MINUS)
		vars->scale -= .1;
	else if (keycode == KEY_PLUS)
		vars->scale += .1;
	else if (keycode == KEY_W)
		vars->alpha -= M_PI * 5 / 180;
	else if (keycode == KEY_S)
		vars->alpha += M_PI * 5 / 180;
	else if (keycode == KEY_A)
		vars->beta += M_PI * 5 / 180;
	else if (keycode == KEY_D)
		vars->beta -= M_PI * 5 / 180;
	else if (keycode == KEY_Q)
		vars->gamma -= M_PI * 5 / 180;
	else if (keycode == KEY_E)
		vars->gamma += M_PI * 5 / 180;
	return (0);
}
