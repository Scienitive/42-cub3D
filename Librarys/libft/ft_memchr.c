/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onermorkoc <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:07:26 by onermorko         #+#    #+#             */
/*   Updated: 2022/01/28 15:12:00 by onermorko        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dizi;
	size_t			i;

	dizi = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (dizi[i] == (unsigned char)c)
			return ((void *)&dizi[i]);
		i++;
	}
	return (0);
}
