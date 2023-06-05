/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:58:32 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/05 15:35:44 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void ft_parsing(char **argv, t_data *data)
{
	check_file_ext(argv[1]);
	init_struct(data);
	
}

int	main(int argc, char **argv)
{
	t_data		data;
	
	if (argc != 2)
		error_msg("Incorrect amount of arguments\n");
	ft_parsing(argv, &data);
	return (0);
}