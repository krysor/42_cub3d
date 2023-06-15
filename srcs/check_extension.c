/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:56:09 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/15 12:09:54 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	error_msg(char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	check_file_ext1(char *ptr)
{
	int	i;

	if (ft_strlen(ptr) <= ft_strlen(".cub"))
		error_msg("The input file name is too short\n");
	i = 0;
	while (*ptr != '\0')
		ptr++;
	if (ft_strncmp(ptr - 4, ".cub", 4) != 0)
		error_msg("The input file extenstion is not .cub\n");
}

void	check_extension(char *str)
{
	char	*ptr;

	ptr = str;
	if (!ft_strchr(ptr, '.'))
		error_msg("The input file has no extension\n");
	else
		check_file_ext1(ptr);
}
