/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:16:18 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/06/06 11:31:39 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	raycasting(t_data *data)
{
	t_raycast	raycast;
	int			x;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		raycast.camera_x = 2 * x / WINDOW_WIDTH - 1;
		init_raycast(&raycast, data);
		dda(&raycast, data);
	}
}

void	dda(t_raycast *rc, t_data *data)
{
	
}
