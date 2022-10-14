/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omorkoc <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:20:01 by omorkoc           #+#    #+#             */
/*   Updated: 2022/08/31 14:32:41 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_data_rc(t_cub3d *s_cub3d, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH -1;
	s_cub3d->raydir_x = s_cub3d->dir_x + s_cub3d->plane_x * camera_x;
	s_cub3d->raydir_y = s_cub3d->dir_y + s_cub3d->plane_y * camera_x;
	s_cub3d->map_x = (int)s_cub3d->pos_x;
	s_cub3d->map_y = (int)s_cub3d->pos_y;
	s_cub3d->delta_dist_x = fabs(1 / s_cub3d->raydir_x);
	s_cub3d->delta_dist_y = fabs(1 / s_cub3d->raydir_y);
	s_cub3d->hit = 0;
}

int	print_map(t_cub3d *s_cub3d)
{
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		set_data_rc(s_cub3d, x);
		print_map2(s_cub3d);
		print_map3(s_cub3d);
		print_map4(s_cub3d);
		print_map5(s_cub3d, x);
		x++;
	}
	mlx_put_image_to_window(s_cub3d->mlx_ptr, s_cub3d->win_ptr, \
		s_cub3d->screen_img, 0, 0);
	return (0);
}

void	key_press_helper3(t_cub3d *s_cub3d, int key)
{
	if (key == RIGHT)
	{
		if (s_cub3d->map3[(int)s_cub3d->pos_x][(int)(s_cub3d->pos_y \
			- (s_cub3d->dir_x * s_cub3d->move_speed))] != 1)
			s_cub3d->pos_y -= s_cub3d->dir_x * s_cub3d->move_speed;
		if (s_cub3d->map3[(int)(s_cub3d->pos_x + (s_cub3d->dir_y \
			* s_cub3d->move_speed))][(int)s_cub3d->pos_y] != 1)
			s_cub3d->pos_x += s_cub3d->dir_y * s_cub3d->move_speed;
	}
	if (key == LEFT)
	{
		if (s_cub3d->map3[(int)(s_cub3d->pos_x)][(int)(s_cub3d->pos_y \
			+ (s_cub3d->dir_x * s_cub3d->move_speed))] != 1)
			s_cub3d->pos_y += s_cub3d->dir_x * s_cub3d->move_speed;
		if (s_cub3d->map3[(int)(s_cub3d->pos_x - (s_cub3d->dir_y \
			* s_cub3d->move_speed))][(int)(s_cub3d->pos_y)] != 1)
			s_cub3d->pos_x -= s_cub3d->dir_y * s_cub3d->move_speed;
	}
}

void	key_press_helper2(t_cub3d *s_cub3d, int key)
{
	double	olddir_x;
	double	oldplane_x;

	if (key == UP)
	{
		if (s_cub3d->map3[(int)(s_cub3d->pos_x + s_cub3d->dir_x \
			* s_cub3d->move_speed)][(int)(s_cub3d->pos_y)] != 1)
			s_cub3d->pos_x += s_cub3d->dir_x * s_cub3d->move_speed;
		if (s_cub3d->map3[(int)(s_cub3d->pos_x)][(int)(s_cub3d->pos_y \
			+ s_cub3d->dir_y * s_cub3d->move_speed)] != 1)
			s_cub3d->pos_y += s_cub3d->dir_y * s_cub3d->move_speed;
	}
	if (key == CAMERA_RIGHT)
	{
		olddir_x = s_cub3d->dir_x;
		s_cub3d->dir_x = s_cub3d->dir_x * cos(-s_cub3d->rot_speed) \
			- s_cub3d->dir_y * sin(-s_cub3d->rot_speed);
		s_cub3d->dir_y = olddir_x * sin(-s_cub3d->rot_speed) \
			+ s_cub3d->dir_y * cos(-s_cub3d->rot_speed);
		oldplane_x = s_cub3d->plane_x;
		s_cub3d->plane_x = s_cub3d->plane_x * cos(-s_cub3d->rot_speed) \
			- s_cub3d->plane_y * sin(-s_cub3d->rot_speed);
		s_cub3d->plane_y = oldplane_x * sin(-s_cub3d->rot_speed) \
			+ s_cub3d->plane_y * cos(-s_cub3d->rot_speed);
	}
}

void	key_press_helper(t_cub3d *s_cub3d, int key)
{
	double	olddir_x;
	double	oldplane_x;

	if (key == BACK)
	{
		if (s_cub3d->map3[(int)(s_cub3d->pos_x - s_cub3d->dir_x \
			* s_cub3d->move_speed)][(int)(s_cub3d->pos_y)] != 1)
			s_cub3d->pos_x -= s_cub3d->dir_x * s_cub3d->move_speed;
		if (s_cub3d->map3[(int)(s_cub3d->pos_x)][(int)(s_cub3d->pos_y \
			- s_cub3d->dir_y * s_cub3d->move_speed)] != 1)
			s_cub3d->pos_y -= s_cub3d->dir_y * s_cub3d->move_speed;
	}
	if (key == CAMERA_LEFT)
	{
		olddir_x = s_cub3d->dir_x;
		s_cub3d->dir_x = s_cub3d->dir_x * cos(s_cub3d->rot_speed) \
			- s_cub3d->dir_y * sin(s_cub3d->rot_speed);
		s_cub3d->dir_y = olddir_x * sin(s_cub3d->rot_speed) \
			+ s_cub3d->dir_y * cos(s_cub3d->rot_speed);
		oldplane_x = s_cub3d->plane_x;
		s_cub3d->plane_x = s_cub3d->plane_x * cos(s_cub3d->rot_speed) \
			- s_cub3d->plane_y * sin(s_cub3d->rot_speed);
		s_cub3d->plane_y = oldplane_x * sin(s_cub3d->rot_speed) \
			+ s_cub3d->plane_y * cos(s_cub3d->rot_speed);
	}
}
