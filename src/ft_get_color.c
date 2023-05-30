/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:00:58 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/02/17 10:40:35 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_t(int trgb);
static int	ft_get_r(int trgb);
static int	ft_get_g(int trgb);
static int	ft_get_b(int trgb);

int	ft_get_color(t_data *data, t_point *p1, t_point *p2)
{
	double			proportion;
	unsigned int	transparency;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	if (p1->color == p2->color)
	{
		data->pixels_left--;
		return (p1->color);
	}
	proportion = (double)data->pixels_left-- / data->pixels_total;
	transparency = (unsigned int)(proportion * ft_get_t(p1->color)
			+ (1 - proportion) * ft_get_t(p2->color));
	red = (unsigned int)(proportion * ft_get_r(p1->color)
			+ (1 - proportion) * ft_get_r(p2->color));
	green = (unsigned int)(proportion * ft_get_g(p1->color)
			+ (1 - proportion) * ft_get_g(p2->color));
	blue = (unsigned int)(proportion * ft_get_b(p1->color)
			+ (1 - proportion) * ft_get_b(p2->color));
	return ((transparency << 24) | (red << 16) | (green << 8) | blue);
}

static int	ft_get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

static int	ft_get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

static int	ft_get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

static int	ft_get_b(int trgb)
{
	return (trgb & 0xFF);
}
