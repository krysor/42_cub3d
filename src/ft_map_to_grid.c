/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:01:02 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/02/16 12:16:43 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	**ft_fd_to_grid(int fd, t_point **grid);
static void		ft_exit(t_point **grid, char *err_msg);
static int		ft_create_row(t_point **grid, char **arr, t_point **last_down);
static void		ft_connect_rows(t_point **last_down, t_point **last_down_old);

t_point	**ft_map_to_grid(char *map, t_point **grid)
{
	int	fd;

	grid = malloc(sizeof(t_point *));
	if (!grid)
		ft_exit(grid, "ft_map_to_grid: malloc");
	*grid = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_exit(grid, "ft_map_to_grid: open");
	grid = ft_fd_to_grid(fd, grid);
	if (close(fd) == -1)
		ft_exit(grid, "ft_map_to_grid: close");
	return (grid);
}

static void	ft_exit(t_point **grid, char *err_msg)
{
	perror(err_msg);
	ft_free_grid(grid);
	exit(1);
}

static t_point	**ft_fd_to_grid(int fd, t_point **grid)
{
	char	*next_line;
	char	**arr;
	int		size_row;
	int		size_row_old;
	t_point	*last_down;

	next_line = get_next_line(fd);
	if (!next_line)
		ft_exit(grid, "get_next_line: empty map");
	while (next_line)
	{
		arr = ft_split(next_line, ' ');
		free(next_line);
		if (!arr)
			ft_exit(grid, "ft_split");
		size_row = ft_create_row(grid, arr, &last_down);
		ft_free_arr(arr);
		if ((*grid)->next_down && size_row != size_row_old)
			ft_exit(grid, "map: not all rows have equal size");
		size_row_old = size_row;
		next_line = get_next_line(fd);
	}
	ft_center_axes(grid);
	return (grid);
}

static int	ft_create_row(t_point **grid, char **arr, t_point **last_down)
{
	int		x;
	t_point	*point;
	t_point	*last_right;
	t_point	*last_down_old;

	last_down_old = *last_down;
	x = 0;
	while (arr[x] && *arr[x] != '\n')
	{
		point = ft_pointnew(arr[x], x);
		if (!point)
		{
			ft_free_arr(arr);
			ft_exit(grid, "ft_pointnew: incorrect point format");
		}
		if (x == 0)
			ft_gridadd_down(grid, point, &last_right, last_down);
		else
			ft_gridadd_right(grid, point, &last_right, last_down);
		x++;
	}
	if ((*grid)->next_down)
		ft_connect_rows(last_down, &last_down_old);
	return (x);
}

static void	ft_connect_rows(t_point **last_down, t_point **last_down_old)
{
	t_point	*row1;
	t_point	*row2;

	row1 = *last_down_old;
	row2 = *last_down;
	while (row1)
	{
		row1->next_down = row2;
		row1 = row1->next_right;
		row2 = row2->next_right;
	}
}
