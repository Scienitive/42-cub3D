/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omorkoc <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:45:05 by omorkoc           #+#    #+#             */
/*   Updated: 2022/08/31 14:46:16 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	**copy_int_array(int **array, int size)
{
	int	i;
	int	j;
	int	**new_arr;

	new_arr = malloc(sizeof(int *) * size);
	i = -1;
	while (++i < size)
	{
		new_arr[i] = malloc(sizeof(int) * size);
		j = -1;
		while (++j < size)
			new_arr[i][j] = array[i][j];
	}
	return (new_arr);
}

void	free_int_array(int **array, int map_size)
{
	int		i;

	i = -1;
	while (++i < map_size)
		free(array[i]);
	free(array);
}

void	free_char_array(char **array)
{
	int		i;

	if (array)
	{
		i = -1;
		while (array[++i])
			free(array[i]);
		free(array);
	}
}

int	rbg_to_int(int r, int g, int b)
{
	return (((r & 0x0ff) << 16) | ((g & 0x0ff) << 8) | (b & 0x0ff));
}

void	ft_exit(t_cub3d *s_cub3d)
{
	ft_free_all(s_cub3d);
	exit(0);
}
