/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onermorkoc <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:58:21 by onermorko         #+#    #+#             */
/*   Updated: 2022/01/31 08:25:24 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*hedef;
	char	*kaynak;

	if (!dest && !src)
		return (NULL);
	hedef = (char *)dest;
	kaynak = (char *)src;
	i = 0;
	while (i < n)
	{
		hedef[i] = kaynak[i];
		i++;
	}
	return ((void *)hedef);
}
