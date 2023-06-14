/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:56:09 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/07 12:46:46 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void error_msg(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

// void check_file_ext1(char *ptr)
// {
// 	int i;

// 	i = 0;
// 	while (*ptr != '\0')
// 		ptr++;
// 	if (ft_strncmp(ptr - 4, ".cub", 4) != 0)
// 		error_msg("Not a .cub file\n");
// }

void check_extension(char *str)
{
	if (!ft_strchr(str, 46))
		error_msg("Not a .cub file\n");
	else
	{
		while (*str)
			str++;
		if (ft_strncmp(str - 4, ".cub", 4) != 0)
			error_msg("Not a .cub file\n");
	}
}
