/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onermorkoc <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:42:50 by onermorko         #+#    #+#             */
/*   Updated: 2022/01/28 15:15:51 by onermorko        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*dest;
	char			*source;

	dest = (char *)dst;
	source = (char *)src;
	if (dest > source)
	{
		while (n-- > 0)
			dest[n] = source[n];
	}
	else
	{
		ft_memcpy(dest, source, n);
	}
	return ((void *)dest);
}
