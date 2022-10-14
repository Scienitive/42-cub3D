/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omorkoc <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:19:09 by omorkoc           #+#    #+#             */
/*   Updated: 2022/08/23 23:19:14 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_free_map(t_cub3d *s_cub3d)
{
	if (s_cub3d->map)
		free(s_cub3d->map);
	if (s_cub3d->no_bool == 1)
		free(s_cub3d->imgs[0]);
	if (s_cub3d->so_bool == 1)
		free(s_cub3d->imgs[1]);
	if (s_cub3d->we_bool == 1)
		free(s_cub3d->imgs[2]);
	if (s_cub3d->ea_bool == 1)
		free(s_cub3d->imgs[3]);
	if (s_cub3d->f_bool == 1)
		free(s_cub3d->imgs[4]);
	if (s_cub3d->c_bool == 1)
		free(s_cub3d->imgs[5]);
	if (s_cub3d->map2_bool == 1)
		free(s_cub3d->map2);
	if (s_cub3d->imgs)
		free(s_cub3d->imgs);
	return (0);
}

void	ft_free_helper(t_cub3d *s_cub3d)
{
	free(s_cub3d->f_rgb);
	free(s_cub3d->c_rgb);
	free_int_array(s_cub3d->map3, s_cub3d->map_size);
}

int	ft_free_all(t_cub3d *s_cub3d)
{
	ft_free_helper(s_cub3d);
	ft_free_map(s_cub3d);
	return (0);
}

int	ft_error(int key_code)
{
	if (key_code == 0)
		printf("Error!\nArgüman sayısı 1 olmalı (map)\n");
	else if (key_code == 1)
		printf("Error!\nHaritanın uzantısında sorunlar mevcut\n");
	else if (key_code == 2)
		printf("Error!\nDosya bulunamadı\n");
	else if (key_code == 3)
		printf("Error!\nGeçersiz harita\n");
	else if (key_code == 4)
		printf("Error!\nHaritanın içinde oyuncu bulunamadı(N, E, S, W)\n");
	else if (key_code == 5)
		printf("Error!\nHaritanın içinde birden fazla oyuncu var\n");
	else if (key_code == 6)
		printf("Error!\nHaritanın içinde geçersiz karakter mevcut\n");
	else if (key_code == 7)
		printf("Error!\nHaritanın satırlar arasında '\\n' mevcut\n");
	else if (key_code == 8)
		printf("Error!\nGeçersiz RGB renk kodu\n");
	else if (key_code == 9)
		printf("Error!\nVerilen konumda resim bulunamadı\n");
	else if (key_code == 10)
		printf("Error!\nHarita kapalı degil\n");
	return (1);
}

int	check_arg(char *map)
{
	int		last_index;

	last_index = ft_strlen(map) - 1;
	if (map[last_index] != 'b')
		return (1);
	else if (map[last_index - 1] != 'u')
		return (1);
	else if (map[last_index - 2] != 'c')
		return (1);
	else if (map[last_index - 3] != '.')
		return (1);
	return (0);
}
