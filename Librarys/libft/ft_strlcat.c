/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onermorkoc <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:22:38 by omorkoc           #+#    #+#             */
/*   Updated: 2022/01/28 15:29:02 by onermorko        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_boyut;
	size_t	src_boyut;

	i = 0;
	dst_boyut = ft_strlen(dst);
	src_boyut = ft_strlen(src);
	if (dst_boyut >= size)
		return (size + src_boyut);
	while (src[i] && dst_boyut + i < size - 1)
	{
		dst[dst_boyut + i] = src[i];
		i++;
	}
	dst[dst_boyut + i] = '\0';
	return (dst_boyut + src_boyut);
}
