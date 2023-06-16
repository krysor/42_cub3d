/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:01:14 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/16 15:31:52 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../includes/get_next_line.h"

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
	int				i_line_map_start;
	int				len_map;
	char			**map;
	t_rgb			rgb[2];
	t_tex_parsing	tex_parsing;
	int				x;
	int				y;
}	t_data;

/* Functions */

void	allocate_map_utils(t_data *data, char *argv[]);
void	allocate_map(t_data *data, char *argv[]);
void	error_msg(char *str);
void	check_extension(char *str);
int		line_is_map(char *ret);
void	check_wrong_char(char **map, int len_map);
void	check_dup_char(char **map);
void	check_empty_line(char **map);
void	check_map(char **map, t_data *data);
void	check_gaps(char **map, int len_map);
int		check_lastchar(char *str);
void	check_delim_char(char **map);
void	check_delim_line(char **map, int len_map);
void	check_overflow(int r, int g, int b);
void	populate_texture(int idx, t_data *data, int *count, char *ret);
void	color_check(char **split, t_data *data);
void	populate_rgb(int idx, t_data *data, int *count, char *ret);
void	browse_file(t_data *data, char **argv);
void	init_rgb(t_rgb *rgb);
void	init_texture(t_tex_parsing tex);
void	init_struct(t_data *data);
int		line_is_empty(char *ret);
int		is_space(char c);
int		skip_space(char *ret);
void	open_file(t_data *data, char *argv[]);
void	browse_map_cond(char *ret, t_data *data, int *count);
void	free_split(char **split);
void	free_alloc(t_data *data);
void	free_data(t_data *data);

#endif