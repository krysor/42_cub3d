/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:01:14 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/01 14:17:46 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_tex_parsing
{
	char	*texture[4];
}	t_tex_parsing;

/* 0 Floor, 1 Ceiling */
typedef struct s_data
{
	int				fd;
	int				count_file;
	int				count_map;
	char			**map;
	t_rgb			rgb[2];
	t_tex_parsing	tex_parsing;
	int				x;
	int				y;
}	t_data;

/* Functions */

#endif