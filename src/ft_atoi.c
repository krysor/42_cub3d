/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:59:22 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/02/16 12:49:01 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_nbhex(char *s);
static int	ft_ishex(char chr);
static int	ft_nbdigit(char *s);

long int	ft_atoli(const char *nptr)
{
	long int	nb;
	int			sign;
	char		*str;

	nb = 0;
	sign = 1;
	str = (char *)nptr;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (!ft_isdigit(*str) || (ft_nbdigit(str) > 10))
		return (LONG_MIN);
	while (ft_isdigit(*str))
		nb = nb * 10 + *str++ - '0';
	if (*str != '\0' && *str != '\n' && *str != ',')
		return (LONG_MIN);
	nb *= sign;
	return (nb);
}

static int	ft_nbdigit(char *s)
{
	int	nb;

	nb = 0;
	while (*s && ft_isdigit(*s))
	{
		nb++;
		s++;
	}	
	return (nb);
}

long int	ft_hatoli(char *str)
{
	long int	nb;

	if (!str)
		return (WHITE);
	str++;
	if (*str == '-')
		(LONG_MIN);
	else if (*str == '+')
		str++;
	if (!ft_ishex(*str) || (ft_nbhex(str) > 8))
		return (LONG_MIN);
	nb = 0;
	while (ft_ishex(*str))
	{
		if (ft_isdigit(*str))
			nb = nb * 16 + *str++ - '0';
		if ('a' <= *str && *str <= 'f')
			nb = nb * 16 + ((long int)(*str++ - 'a') + 10);
		if ('A' <= *str && *str <= 'F')
			nb = nb * 16 + ((long int)(*str++ - 'A') + 10);
	}	
	if (*str != '\0' && *str != '\n' && *str != ',')
		return (LONG_MIN);
	return (nb);
}

static int	ft_ishex(char chr)
{
	if (ft_isdigit(chr)
		|| ('a' <= chr && chr <= 'f')
		|| ('A' <= chr && chr <= 'F'))
		return (1);
	return (0);
}

static int	ft_nbhex(char *s)
{
	int	nb;

	nb = 0;
	while (*s && ft_ishex(*s))
	{
		nb++;
		s++;
	}	
	return (nb);
}
