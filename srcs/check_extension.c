/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:56:09 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/14 12:01:07 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void    error_msg(char *str)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(str, 2);
    exit(EXIT_FAILURE);
}

void    check_file_ext1(char *ptr)
{
    int         i;    i = 0;
    while (*ptr != '\0')
        ptr++;
    if (ft_strncmp(ptr - 4, ".cub", 4) != 0)
        error_msg("The map file should be a .cub file\n");
}

void    check_extension(char *str)
{
    char  *ptr;    ptr = str;
    if (!ft_strchr(ptr, 46))
        error_msg("The map file should be a .cub file\n");
    else
        check_file_ext1(ptr);
}

