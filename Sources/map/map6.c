/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:24:59 by omorkoc           #+#    #+#             */
/*   Updated: 2022/09/02 13:54:27 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_map5_helper(int **new_array, t_cub3d *s_cub3d, int i, int j)
{
	if (!recursive_check(new_array, s_cub3d->map_size, i, j))
	{
		ft_free_helper(s_cub3d);
		free_int_array(new_array, s_cub3d->map_size);
		return (ft_error(10));
	}
	free_int_array(new_array, s_cub3d->map_size);
	return (0);
}
