/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omorkoc <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:06:31 by omorkoc           #+#    #+#             */
/*   Updated: 2022/08/23 23:08:53 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int args_count, char **args_array)
{
	int		fd;
	t_cub3d	s_cub3d;

	if (args_count != 2)
		return (ft_error(0));
	else if (check_arg(args_array[1]))
		return (ft_error(1));
	fd = open(args_array[1], O_RDONLY);
	if (fd < 0)
		return (ft_error(2));
	if (read_map(fd, &s_cub3d))
		return (ft_free_map(&s_cub3d));
	if (start_mlx(&s_cub3d))
		return (ft_free_map(&s_cub3d));
}
