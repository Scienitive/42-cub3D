/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onermorkoc <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:08:09 by onermorko         #+#    #+#             */
/*   Updated: 2022/01/28 15:26:13 by onermorko        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		s_boyut;
	char	*dizi;

	s_boyut = ft_strlen(s) + 1;
	dizi = (char *)malloc(s_boyut * sizeof(char));
	if (!dizi)
		return (NULL);
	return ((char *)ft_memcpy(dizi, s, s_boyut));
}
