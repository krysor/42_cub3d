/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_points.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:24:04 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/02/17 10:41:07 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*ft_next_same_z_vertical(t_data *data,
					t_point *prev, t_point *next);
static t_point	*ft_next_same_z_horizontal(t_data *data,
					t_point *prev, t_point *next);
static void		ft_connect_points(t_data *data, t_point *p1, t_point *p2);

void	ft_connect_alined_horizontal(t_data *data, t_point *p)
{
	t_point	p1;
	t_point	p2;
	t_point	p_temp;

	ft_copy_point(p, &p1);
	ft_scale_point(&p1, data->scale);
	ft_rotate_point(&p1, data->alpha, data->beta, data->gamma);
	while (p1.next_right)
	{
		ft_copy_point(ft_next_same_z_horizontal(data, &p1, &p2), &p2);
		ft_scale_point(&p2, data->scale);
		ft_rotate_point(&p2, data->alpha, data->beta, data->gamma);
		if (p1.x <= p2.x)
		{
			ft_connect_points(data, &p1, &p2);
			ft_copy_point(&p2, &p1);
		}
		else
		{
			ft_copy_point(&p2, &p_temp);
			ft_connect_points(data, &p2, &p1);
			ft_copy_point(&p_temp, &p1);
		}
	}
}

void	ft_connect_alined_vertical(t_data *data, t_point *p)
{
	t_point	p1;
	t_point	p2;
	t_point	p_temp;

	ft_copy_point(p, &p1);
	ft_scale_point(&p1, data->scale);
	ft_rotate_point(&p1, data->alpha, data->beta, data->gamma);
	while (p1.next_down)
	{
		ft_copy_point(ft_next_same_z_vertical(data, &p1, &p2), &p2);
		ft_scale_point(&p2, data->scale);
		ft_rotate_point(&p2, data->alpha, data->beta, data->gamma);
		if (p1.x <= p2.x)
		{
			ft_connect_points(data, &p1, &p2);
			ft_copy_point(&p2, &p1);
		}
		else
		{
			ft_copy_point(&p2, &p_temp);
			ft_connect_points(data, &p2, &p1);
			ft_copy_point(&p_temp, &p1);
		}
	}
}

static t_point	*ft_next_same_z_vertical(t_data *data,
					t_point *prev, t_point *next)
{
	t_point	*temp;

	ft_copy_point(prev->next_down, next);
	temp = next->next_down;
	while (temp && next->color == temp->color
		&& ((data->alpha == 0 && data->beta == 0)
			|| (next->z == temp->z && prev->z == temp->z)))
	{
		ft_copy_point(temp, next);
		temp = temp->next_down;
	}
	return (next);
}

static t_point	*ft_next_same_z_horizontal(t_data *data,
					t_point *prev, t_point *next)
{
	t_point	*temp;

	ft_copy_point(prev->next_right, next);
	temp = next->next_right;
	while (temp && next->color == temp->color
		&& ((data->alpha == 0 && data->beta == 0)
			|| (next->z == temp->z && prev->z == temp->z)))
	{
		ft_copy_point(temp, next);
		temp = temp->next_right;
	}
	return (next);
}

static void	ft_connect_points(t_data *d, t_point *p1, t_point *p2)
{
	double			slope;
	double			intercept;
	unsigned int	color;

	d->pixels_total = abs(p2->x - p1->x) + abs(p2->y - p1->y);
	d->pixels_left = d->pixels_total;
	if (p1->x != p2->x)
	{
		slope = (double)(p2->y - p1->y) / (double)(p2->x - p1->x);
		intercept = p1->y - slope * p1->x;
	}
	while (d->pixels_left)
	{		
		color = ft_get_color(d, p1, p2);
		if (p1->x == p2->x && p1->y < p2->y)
			my_pixel_put(d, d->x_mid + p1->x, d->y_mid + p1->y++, color);
		else if (p1->x == p2->x && p1->y > p2->y)
			my_pixel_put(d, d->x_mid + p1->x, d->y_mid + p1->y--, color);
		else if (p1->y == round(slope * p1->x + intercept))
			my_pixel_put(d, d->x_mid + p1->x++, d->y_mid + p1->y, color);
		else if (p1->y < p2->y)
			my_pixel_put(d, d->x_mid + p1->x, d->y_mid + p1->y++, color);
		else if (p1->y > p2->y)
			my_pixel_put(d, d->x_mid + p1->x, d->y_mid + p1->y--, color);
	}
}
