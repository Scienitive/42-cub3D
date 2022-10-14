/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omorkoc <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:48:11 by omorkoc           #+#    #+#             */
/*   Updated: 2022/01/28 15:20:24 by onermorko        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*dizi;
	size_t	i;

	i = 0;
	dizi = (char *)b;
	while (i < len)
	{
		dizi[i] = c;
		i++;
	}
	return ((void *)dizi);
}
