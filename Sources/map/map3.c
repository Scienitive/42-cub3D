/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omorkoc <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 00:56:27 by omorkoc           #+#    #+#             */
/*   Updated: 2022/08/29 22:44:39 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_digit(char *array)
{
	int		i;

	i = -1;
	while (array[++i])
		if (!ft_isdigit(array[i]))
			return (1);
	return (0);
}

int	check_f_c(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	if (i != 3)
		return (ft_error(8));
	i = -1;
	while (array[++i])
		if (check_digit(array[i]))
			return (ft_error(8));
	i = -1;
	while (array[++i])
		if (!(ft_atoi(array[i]) >= 0 && ft_atoi(array[i]) <= 255))
			return (ft_error(8));
	return (0);
}

int	setup_f_c(t_cub3d *s_cub3d)
{
	int		i;
	char	**array_f;
	char	**array_c;

	array_f = ft_split(s_cub3d->imgs[4], ',');
	array_c = ft_split(s_cub3d->imgs[5], ',');
	if (check_f_c(array_c) || check_f_c(array_f))
	{
		free_char_array(array_c);
		free_char_array(array_f);
		return (1);
	}
	s_cub3d->f_rgb = (int *)malloc(sizeof(int) * 3);
	s_cub3d->c_rgb = (int *)malloc(sizeof(int) * 3);
	i = -1;
	while (++i < 3)
	{
		s_cub3d->f_rgb[i] = ft_atoi(array_f[i]);
		s_cub3d->c_rgb[i] = ft_atoi(array_c[i]);
	}
	free_char_array(array_c);
	free_char_array(array_f);
	return (setup_int_map(s_cub3d));
}

int	check_map4(t_cub3d *s_cub3d)
{
	int		i;

	i = 0;
	while (s_cub3d->map2[i])
	{
		if (s_cub3d->map2[i] == '\n' && (s_cub3d->map2[i + 1] != '1' \
		&& s_cub3d->map2[i + 1] != '\t' && s_cub3d->map2[i + 1] != ' '))
			return (ft_error(7));
		else if ((s_cub3d->map2[i] == '\t' || s_cub3d->map2[i] == ' ') \
		&& (s_cub3d->map2[i + 1] == '\n'))
			return (ft_error(7));
		i++;
	}
	return (setup_f_c(s_cub3d));
}
