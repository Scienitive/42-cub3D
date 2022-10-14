/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:13:40 by omorkoc           #+#    #+#             */
/*   Updated: 2022/08/30 23:21:19 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setup_int_map3(t_cub3d *s_cub3d)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	x = 0;
	y = 0;
	while (s_cub3d->map2[++i])
	{
		if (s_cub3d->map2[i] == '\n')
		{
			x = -1;
			y++;
		}
		else if (s_cub3d->map2[i] != '\t' && s_cub3d->map2[i] != ' ')
			int_map_helper(s_cub3d, i, x, y);
		x++;
	}
}

void	setup_int_map2(t_cub3d *s_cub3d, int map_width, int map_height)
{
	int		i;
	int		j;

	i = -1;
	s_cub3d->map3 = (int **)malloc(sizeof(int *) * map_width);
	while (++i < map_width)
		s_cub3d->map3[i] = (int *)malloc(sizeof(int) * map_height);
	i = -1;
	while (++i < map_width)
	{
		j = -1;
		while (++j < map_height)
			s_cub3d->map3[i][j] = 0;
	}
	setup_int_map3(s_cub3d);
}

int	ft_strlen_mod(char *array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		if (array[i] == '\t')
			i += TAB_SIZE;
		else
			i++;
	}
	return (i);
}

int	check_max_number(char **array, int number, int skip)
{
	int		i;

	i = -1;
	while (array[++i])
		if (number < (int)ft_strlen_mod(array[i]) && i != skip)
			return (-1);
	return (1);
}

int	setup_int_map(t_cub3d *s_cub3d)
{
	char	**array;
	int		i;
	int		map_width;
	int		map_height;

	array = ft_split(s_cub3d->map2, '\n');
	i = -1;
	while (array[++i])
		if (check_max_number(array, ft_strlen_mod(array[i]), i) == 1)
			break ;
	map_width = ft_strlen_mod(array[i]);
	i = -1;
	map_height = 0;
	while (s_cub3d->map2[++i])
		if (s_cub3d->map2[i] == '\n')
			map_height++;
	if (map_width < map_height)
		map_width = map_height;
	else
		map_height = map_width;
	s_cub3d->map_size = map_height;
	free_char_array(array);
	setup_int_map2(s_cub3d, map_width, map_height);
	return (check_map5(s_cub3d));
}
