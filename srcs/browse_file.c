/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:53:14 by dsoroko           #+#    #+#             */
/*   Updated: 2023/06/16 11:47:52 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	check_values(char **split, t_data *data)
{
	int		i;
	char	*msg;

	i = -1;
	while (++i < 3)
	{
		if (ft_strlen(split[i]) == 0 || ft_strlen(split[i]) > 3)
		{
			msg = "Input color rgb value is not between 0 and 255\n";
			break ;
		}
		if (ft_strlen(split[i]) == 3 && ft_strncmp("255", split[i], 3) < 0)
		{
			msg = "Input color rgb value is higher than 255\n";
			break ;
		}
	}
	if (i < 3)
	{
		free_data(data);
		error_msg(msg);
	}
}

// void	check_overflow(int r, int g, int b)
// {
// 	if (r > 255 || g > 255 || b > 255)
// 		error_msg("Texture resolution above 255\n");
// 	else if (r < 0 || g < 0 || b < 0)
// 		error_msg("Texture resolution are negative\n");
// }

void	populate_texture(int idx, t_data *data, int *count, char *ret)
{
	int	i;

	if (*(ret + 2) != ' ')
	{
		free_data(data);
		error_msg("Incorrect texture identifier found\n");
	}
	i = skip_space(ret + 2);
	data->tex_parsing.texture[idx] = ft_strdup(ret + i + 2);
	if (data->tex_parsing.texture[idx] == NULL)
	{
		free_data(data);
		error_msg("malloc fail inside ft_strdup inside populate_texture\n");
	}
	i = ft_strlen(data->tex_parsing.texture[idx]);
	while (is_space(data->tex_parsing.texture[idx][i - 1])
		|| data->tex_parsing.texture[idx][i - 1] == '\n')
	{
		data->tex_parsing.texture[idx][i - 1] = '\0';
		i--;
	}
	*count += 1;
}

void	color_check(char **split, t_data *data)
{
	int		i;
	char	*temp;

	i = -1;
	while (split[++i])
	{	
		temp = ft_strtrim(split[i], " \n");
		if (temp == NULL || *temp == '\0')
		{
			free(temp);
			break ;
		}
		free(split[i]);
		split[i] = temp;
		while (ft_isdigit(*temp))
			temp++;
		if (*temp != '\0')
			break ;
	}
	if (i < 3)
	{
		free_data(data);
		error_msg("Error during the parsing of a color line\n");
	}
}

/* Split rgb values, perform check on rgb values, atoi rgb values, free split */
void	populate_rgb(int idx, t_data *data, int *count, char *ret)
{
	int		i;
	char	**split;

	if (*(ret + 1) != ' ')
	{
		free_data(data);
		error_msg("Incorrect color identifier found\n");
	}
	i = skip_space(ret + 1);
	split = ft_split(ret + i, ',');
	if (split == NULL)
	{
		free_data(data);
		error_msg("malloc fail inside ft_split inside populate_rgb\n");
	}
	color_check(split, data);
	check_values(split, data);
	data->rgb[idx].r = ft_atoi(split[0]);
	data->rgb[idx].g = ft_atoi(split[1]);
	data->rgb[idx].b = ft_atoi(split[2]);
	free_split(split);
	*count += 1;
}

void	browse_file(t_data *data, char **argv)
{
	char	*ret;
	int		count;

	count = 0;
	open_file(data, argv);
	if (data->fd < 0)
		error_msg("Can't open the input file\n");
	ret = get_next_line(data->fd);
	while (ret)
	{
		browse_map_cond(ret, data, &count);
		if (data->len_map == 0)
			data->count_file++;
		free(ret);
		ret = get_next_line(data->fd);
	}
	if (count != 6)
	{
		free_data(data);
		error_msg("A texture or a color line missing in the input file\n");
	}
	close(data->fd);
	data->fd = -1;
}
