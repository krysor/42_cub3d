/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:25:05 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/02/16 12:56:48 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*ft_pointnew(char *str, int x)
{
	t_point		*point;
	long int	z;
	long int	color;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	z = ft_atoli(str);
	color = ft_hatoli(ft_memchr(str, 'x', ft_strlen(str)));
	if (z < (long int)INT_MIN || z > (long int)INT_MAX
		|| color < 0 || color > (long int)UINT_MAX)
	{
		free(point);
		return (NULL);
	}
	point->x = x;
	point->z = -(int)z;
	point->color = (unsigned int)color;
	point->next_right = NULL;
	point->next_down = NULL;
	return (point);
}

void	ft_copy_point(t_point *src, t_point *dst)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
	dst->color = src->color;
	dst->next_right = src->next_right;
	dst->next_down = src->next_down;
}

void	ft_scale_point(t_point *p, double factor)
{
	p->x = p->x * factor;
	p->y = p->y * factor;
	p->z = p->z * factor;
}

void	ft_rotate_point(t_point *p, double a, double b, double g)
{
	double	x_temp;

	x_temp = p->x * (cos(b) * cos(g))
		+ p->y * ((sin(a) * sin(b) * cos(g)) - (cos(a) * sin(g)))
		+ p->z * ((cos(a) * sin(b) * cos(g)) + (sin(a) * sin(g)));
	p->y = p->x * (cos(b) * sin(g))
		+ p->y * ((sin(a) * sin(b) * sin(g)) + (cos(a) * cos(g)))
		+ p->z * ((cos(a) * sin(b) * sin(g)) - (sin(a) * cos(g)));
	p->x = x_temp;
}
