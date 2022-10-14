/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:09:21 by omorkoc           #+#    #+#             */
/*   Updated: 2022/08/31 14:50:54 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../Librarys/libft/libft.h"
# include "../Librarys/minilibx-linux/mlx.h"
//# include "../Librarys/minilibx-macos/mlx.h"

# define WIN_WIDTH 1500
# define WIN_HEIGHT 850
# define IMG_WIDTH 64
# define IMG_HEIGHT 64
# define TAB_SIZE 8
# define UP 119		// w tuşu
# define BACK 115	// s tuşu
# define RIGHT 97	// a tuşu
# define LEFT 100	// d tuşu
# define CAMERA_RIGHT 65361	//Macos: 123
# define CAMERA_LEFT 65363	//Macos: 124
# define ESC 65307		//Macos: 53

typedef struct s_cub3d
{
	int		*f_rgb;
	int		*c_rgb;
	int		f_bool;
	int		c_bool;
	int		no_bool;
	int		so_bool;
	int		we_bool;
	int		ea_bool;
	int		map2_bool;
	int		**imgs_data;
	int		*screen_img_data;
	int		img_x;
	int		img_y;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		**map3;
	int		map_size;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	char	*map;
	char	**imgs;
	char	*map2;
	void	*screen_img;
	void	*mlx_ptr;
	void	*win_ptr;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	double	raydir_x;
	double	raydir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	double	step;
	double	tex_pos;
}t_cub3d;

int		start_mlx(t_cub3d *s_cub3d);
int		check_double_data(t_cub3d *s_cub3d, int data_key_code);
int		ft_error(int key_code);
int		check_arg(char *map);
int		read_map(int fd, t_cub3d *s_cub3d);
int		ft_free_map(t_cub3d *s_cub3d);
int		ft_free_all(t_cub3d *s_cub3d);
int		check_map2(t_cub3d *s_cub3d);
int		check_map4(t_cub3d *s_cub3d);
int		setup_int_map(t_cub3d *s_cub3d);
int		check_map5(t_cub3d *s_cub3d);
int		**copy_int_array(int **array, int size);
int		rbg_to_int(int r, int g, int b);
int		print_map(t_cub3d *s_cub3d);
int		check_map5_helper(int **new_array, t_cub3d *s_cub3d, int i, int j);
int		recursive_check(int **array, int size, int y, int x);
char	*get_data_value(t_cub3d *s_cub3d, int index, int mode);
void	print_c_rgb(t_cub3d *s_cub3d);
void	print_f_rgb(t_cub3d *s_cub3d);
void	print_map3(t_cub3d *s_cub3d);
void	print_map4(t_cub3d *s_cub3d);
void	print_map5(t_cub3d *s_cub3d, int x);
void	ft_exit(t_cub3d *s_cub3d);
void	key_press_helper(t_cub3d *s_cub3d, int key);
void	key_press_helper2(t_cub3d *s_cub3d, int key);
void	int_map_helper(t_cub3d *s_cub3d, int i, int x, int y);
void	setup_imgs(t_cub3d *s_cub3d, int index, int data_key_code);
void	free_char_array(char **array);
void	free_int_array(int **array, int map_size);
void	ft_free_helper(t_cub3d *s_cub3d);
void	key_press_helper3(t_cub3d *s_cub3d, int key);
void	print_map2(t_cub3d *s_cub3d);

#endif
