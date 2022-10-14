/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omorkoc <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:20:01 by omorkoc           #+#    #+#             */
/*   Updated: 2022/08/31 12:51:48 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int key, t_cub3d *s_cub3d)
{
	key_press_helper(s_cub3d, key);
	key_press_helper2(s_cub3d, key);
	key_press_helper3(s_cub3d, key);
	if (key == ESC)
		ft_exit(s_cub3d);
	mlx_clear_window(s_cub3d->mlx_ptr, s_cub3d->win_ptr);
	print_c_rgb(s_cub3d);
	print_f_rgb(s_cub3d);
	print_map(s_cub3d);
	return (0);
}

void	print_c_rgb(t_cub3d *s_cub3d)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT / 2)
			s_cub3d->screen_img_data[y * WIN_WIDTH + x] = \
				rbg_to_int(s_cub3d->c_rgb[0], s_cub3d->c_rgb[1], \
					s_cub3d->c_rgb[2]);
	}
}

void	print_f_rgb(t_cub3d *s_cub3d)
{
	int		x;
	int		y;

	x = 0;
	y = WIN_HEIGHT / 2;
	while (x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		s_cub3d->screen_img_data[y * WIN_WIDTH + x] = \
			rbg_to_int(s_cub3d->f_rgb[0], s_cub3d->f_rgb[1], \
				s_cub3d->f_rgb[2]);
		x++;
		if (x == WIN_WIDTH)
		{
			y++;
			x = 0;
		}
	}
}

int	put_image(t_cub3d *s_cub3d)
{
	int		i;
	void	*img_ptr;

	s_cub3d->imgs_data = (int **)malloc(sizeof(int *) * 4);
	i = -1;
	while (++i < 4)
	{
		img_ptr = mlx_xpm_file_to_image(s_cub3d->mlx_ptr, \
			s_cub3d->imgs[i], &s_cub3d->img_x, &s_cub3d->img_y);
		if (img_ptr == NULL)
			return (ft_error(9));
		s_cub3d->imgs_data[i] = (int *)mlx_get_data_addr(img_ptr, \
			&s_cub3d->bits_per_pixel, &s_cub3d->size_line, &s_cub3d->endian);
	}
	return (0);
}

int	start_mlx(t_cub3d *s_cub3d)
{
	s_cub3d->move_speed = 0.2;
	s_cub3d->rot_speed = 0.2;
	s_cub3d->mlx_ptr = mlx_init();
	s_cub3d->win_ptr = mlx_new_window(s_cub3d->mlx_ptr, \
		WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	s_cub3d->screen_img = mlx_new_image(s_cub3d->mlx_ptr, \
		WIN_WIDTH, WIN_HEIGHT);
	s_cub3d->screen_img_data = (int *)mlx_get_data_addr(s_cub3d->screen_img, \
		&s_cub3d->bits_per_pixel, &s_cub3d->size_line, &s_cub3d->endian);
	if (put_image(s_cub3d))
	{
		ft_free_helper(s_cub3d);
		return (1);
	}
	print_c_rgb(s_cub3d);
	print_f_rgb(s_cub3d);
	print_map(s_cub3d);
	mlx_hook(s_cub3d->win_ptr, 2, 1L << 0, &key_press, s_cub3d);
	mlx_hook(s_cub3d->win_ptr, 17, 0, (void *)ft_exit, s_cub3d);
	mlx_loop(s_cub3d->mlx_ptr);
	return (0);
}
