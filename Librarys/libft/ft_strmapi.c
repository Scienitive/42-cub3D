/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onermorkoc <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:17:32 by onermorko         #+#    #+#             */
/*   Updated: 2022/01/31 12:20:57 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char f(unsigned int, char))
{
	unsigned int	i;
	char			*dizi;

	if (!s)
		return (NULL);
	dizi = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!dizi)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dizi[i] = f(i, s[i]);
		i++;
	}
	dizi[i] = '\0';
	return (dizi);
}
