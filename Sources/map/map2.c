/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omorkoc <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 00:55:55 by omorkoc           #+#    #+#             */
/*   Updated: 2022/08/24 00:56:00 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_map3(t_cub3d *s_cub3d)
{
	int		i;
	int		found;

	i = -1;
	found = 0;
	while (s_cub3d->map2[++i])
	{
		if (s_cub3d->map2[i] == 'N' || s_cub3d->map2[i] == 'W' \
		|| s_cub3d->map2[i] == 'E' || s_cub3d->map2[i] == 'S')
		{
			found = 1;
			break ;
		}
	}
	if (found != 1)
		return (ft_error(4));
	i++;
	while (s_cub3d->map2[i])
	{
		if (s_cub3d->map2[i] == 'N' || s_cub3d->map2[i] == 'W' \
		|| s_cub3d->map2[i] == 'E' || s_cub3d->map2[i] == 'S')
			return (ft_error(5));
		i++;
	}
	return (check_map4(s_cub3d));
}

int	check_map2(t_cub3d *s_cub3d)
{
	int		i;

	i = 0;
	while (s_cub3d->map2[i])
	{
		if (s_cub3d->map2[i] != '1' && s_cub3d->map2[i] != '0' \
		&& s_cub3d->map2[i] != '\t' && s_cub3d->map2[i] != ' ' \
		&& s_cub3d->map2[i] != '\n' && s_cub3d->map2[i] != 'N' \
		&& s_cub3d->map2[i] != 'W' && s_cub3d->map2[i] != 'E' \
		&& s_cub3d->map2[i] != 'S')
			return (ft_error(6));
		i++;
	}
	return (check_map3(s_cub3d));
}

char	*get_data_value(t_cub3d *s_cub3d, int index, int mode)
{
	int		i;
	int		temp;
	char	*array;

	i = 0;
	if (mode == 1)
		while (s_cub3d->map[index] == '\t' || s_cub3d->map[index] == ' ' \
		|| s_cub3d->map[index] == '\n')
			index++;
	else
		while (s_cub3d->map[index] == '\n')
			index++;
	temp = index - 1;
	if (mode == 1)
		while (s_cub3d->map[++temp] != '\n' && s_cub3d->map[temp] != ' ' \
		&& s_cub3d->map[temp] != '\t')
			i++;
	else
		while (s_cub3d->map[++temp] != '\0')
			i++;
	array = ft_substr(s_cub3d->map, index, i);
	return (array);
}

void	setup_imgs(t_cub3d *s_cub3d, int index, int data_key_code)
{
	if (data_key_code == 1)
		s_cub3d->imgs[0] = get_data_value(s_cub3d, index, 1);
	else if (data_key_code == 2)
		s_cub3d->imgs[1] = get_data_value(s_cub3d, index, 1);
	else if (data_key_code == 3)
		s_cub3d->imgs[2] = get_data_value(s_cub3d, index, 1);
	else if (data_key_code == 4)
		s_cub3d->imgs[3] = get_data_value(s_cub3d, index, 1);
	else if (data_key_code == 5)
		s_cub3d->imgs[4] = get_data_value(s_cub3d, index, 1);
	else if (data_key_code == 6)
		s_cub3d->imgs[5] = get_data_value(s_cub3d, index, 1);
}

int	check_double_data(t_cub3d *s_cub3d, int data_key_code)
{
	if (data_key_code == 1 && s_cub3d->no_bool != 1)
		s_cub3d->no_bool = 1;
	else if (data_key_code == 2 && s_cub3d->so_bool != 1)
		s_cub3d->so_bool = 1;
	else if (data_key_code == 3 && s_cub3d->we_bool != 1)
		s_cub3d->we_bool = 1;
	else if (data_key_code == 4 && s_cub3d->ea_bool != 1)
		s_cub3d->ea_bool = 1;
	else if (data_key_code == 5 && s_cub3d->f_bool != 1)
		s_cub3d->f_bool = 1;
	else if (data_key_code == 6 && s_cub3d->c_bool != 1)
		s_cub3d->c_bool = 1;
	else
		return (-1);
	return (0);
}
