/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:10:29 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/16 15:32:11 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	init_rgb(t_rgb *rgb)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		rgb[i].r = 0;
		rgb[i].g = 0;
		rgb[i].b = 0;
		i++;
	}
}

void	init_texture(t_tex_parsing tex)
{
	int	i;

	i = 0;
	while (tex.texture[i])
		tex.texture[i] = NULL;
}

void	init_struct(t_data *data)
{
	data->fd = 0;
	data->i_line_map_start = 0;
	data->len_map = 0;
	data->map = NULL;
	init_rgb(data->rgb);
	init_texture(data->tex_parsing);
	data->x = 0;
	data->y = 0;
}
