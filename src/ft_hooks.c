/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:19:06 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/05/30 14:30:15 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_key_hook(int keycode, t_data *vars)
{
	if (keycode == KEY_ESC)
		mlx_destroy_window(vars->mlx, vars->win);
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
