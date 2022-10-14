/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omorkoc <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:22:40 by omorkoc           #+#    #+#             */
/*   Updated: 2022/08/23 23:49:14 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_data_name(char *data_name)
{
	if (ft_strncmp("NO", data_name, 2) == 0)
		return (1);
	if (ft_strncmp("SO", data_name, 2) == 0)
		return (2);
	if (ft_strncmp("WE", data_name, 2) == 0)
		return (3);
	if (ft_strncmp("EA", data_name, 2) == 0)
		return (4);
	if (ft_strncmp("F ", data_name, 2) == 0)
		return (5);
	if (ft_strncmp("C ", data_name, 2) == 0)
		return (6);
	return (-1);
}

int	check_map_helper(t_cub3d *s_cub3d, int i)
{
	int		data_key_code;
	char	*data_name;

	data_name = (char *)malloc(sizeof(char) * 3);
	data_name[0] = s_cub3d->map[i];
	data_name[1] = s_cub3d->map[i + 1];
	data_name[2] = '\0';
	data_key_code = check_data_name(data_name);
	if (data_key_code == -1 || \
	check_double_data(s_cub3d, data_key_code) == -1)
	{
		free(data_name);
		return (ft_error(3));
	}
	free(data_name);
	setup_imgs(s_cub3d, i + 2, data_key_code);
	return (0);
}

int	check_map(t_cub3d *s_cub3d)
{
	int		i;

	i = 0;
	while (s_cub3d->map[i])
	{
		if (s_cub3d->map[i] == '\n' || s_cub3d->map[i] == ' ' \
		|| s_cub3d->map[i] == '\t')
			i++;
		else
		{
			if (check_map_helper(s_cub3d, i))
				return (1);
			while (s_cub3d->map[i] != '\n')
				i++;
		}
		if (s_cub3d->no_bool == 1 && s_cub3d->so_bool == 1 \
		&& s_cub3d->we_bool == 1 && s_cub3d->ea_bool == 1 \
		&& s_cub3d->f_bool == 1 && s_cub3d->c_bool == 1)
			break ;
	}
	s_cub3d->map2 = get_data_value(s_cub3d, i + 1, 0);
	s_cub3d->map2_bool = 1;
	return (check_map2(s_cub3d));
}

void	put_value_struct(t_cub3d *s_cub3d)
{
	s_cub3d->no_bool = 0;
	s_cub3d->so_bool = 0;
	s_cub3d->we_bool = 0;
	s_cub3d->ea_bool = 0;
	s_cub3d->f_bool = 0;
	s_cub3d->c_bool = 0;
	s_cub3d->imgs = (char **)malloc(sizeof(char *) * 7);
	s_cub3d->imgs[6] = "\0";
}

int	read_map(int fd, t_cub3d *s_cub3d)
{
	char	*array;
	char	*temp;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * 2);
	buff[1] = '\0';
	array = (char *)malloc(sizeof(char) * 2);
	array[1] = '\0';
	while (read(fd, buff, 1))
	{
		temp = ft_strjoin(array, buff);
		free(array);
		array = temp;
	}
	free(buff);
	s_cub3d->map = array;
	put_value_struct(s_cub3d);
	return (check_map(s_cub3d));
}
