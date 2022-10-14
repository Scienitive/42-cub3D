/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:24:59 by omorkoc           #+#    #+#             */
/*   Updated: 2022/08/30 23:23:17 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	recursive_check(int **array, int size, int y, int x)
{
	if (y == size || y == -1 || x == size || x == -1)
		return (0);
	else if (array[y][x] != 9 && array[y][x] != 1)
	{
		array[y][x] = 9;
		if (!recursive_check(array, size, y + 1, x))
			return (0);
		else if (!recursive_check(array, size, y - 1, x))
			return (0);
		else if (!recursive_check(array, size, y, x + 1))
			return (0);
		else if (!recursive_check(array, size, y, x - 1))
			return (0);
	}
	return (1);
}

int	check_map5(t_cub3d *s_cub3d)
{
	int	i;
	int	j;
	int	br;
	int	**new_array;

	br = 0;
	new_array = copy_int_array(s_cub3d->map3, s_cub3d->map_size);
	i = -1;
	while (++i < s_cub3d->map_size)
	{
		j = -1;
		while (++j < s_cub3d->map_size)
		{
			if (new_array[i][j] >= 2)
				br = 1;
			if (br)
				break ;
		}
		if (br)
			break ;
	}
	if (check_map5_helper(new_array, s_cub3d, i, j))
		return (1);
	return (0);
}

void	setup_player_helper(t_cub3d *s_cub3d, int number)
{
	if (number == 4)
	{
		s_cub3d->plane_x = -0.66;
		s_cub3d->dir_y = 1;
	}
	else if (number == 5)
	{
		s_cub3d->plane_y = -0.66;
		s_cub3d->dir_x = -1;
	}
}

int	setup_player(t_cub3d *s_cub3d, int x, int y, int number)
{
	s_cub3d->pos_x = x + 0.5;
	s_cub3d->pos_y = y + 0.5;
	if (number == 2 || number == 4)
	{
		s_cub3d->dir_x = 0;
		s_cub3d->dir_y = -1;
		s_cub3d->plane_x = 0.66;
		s_cub3d->plane_y = 0;
		setup_player_helper(s_cub3d, number);
	}
	else
	{
		s_cub3d->dir_x = 1;
		s_cub3d->dir_y = 0;
		s_cub3d->plane_x = 0;
		s_cub3d->plane_y = 0.66;
		setup_player_helper(s_cub3d, number);
	}
	return (number);
}

void	int_map_helper(t_cub3d *s_cub3d, int i, int x, int y)
{
	int		number;

	if (s_cub3d->map2[i] == 'N')
		number = setup_player(s_cub3d, x, y, 2);
	else if (s_cub3d->map2[i] == 'E')
		number = setup_player(s_cub3d, x, y, 3);
	else if (s_cub3d->map2[i] == 'S')
		number = setup_player(s_cub3d, x, y, 4);
	else if (s_cub3d->map2[i] == 'W')
		number = setup_player(s_cub3d, x, y, 5);
	else
		number = s_cub3d->map2[i] - '0';
	s_cub3d->map3[x][y] = number;
}
