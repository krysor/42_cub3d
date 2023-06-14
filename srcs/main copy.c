/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:58:32 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/07 15:00:33 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void ft_parsing(char **argv, t_data *data)
{
	check_extension(argv[1]);
	init_struct(data);
	generate_map(data, argv);
	allocate_map(data, argv);
}

int	main(int argc, char **argv)
{
	t_data		data;
	
	if (argc != 2)
		error_msg("Incorrect amount of arguments\n");
	ft_parsing(argv, &data);
	check_map(data.map, &data);
	/*Execution*/
	free_alloc(&data);
	return (0);
}