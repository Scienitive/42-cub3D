/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onermorkoc <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:08:53 by onermorko         #+#    #+#             */
/*   Updated: 2022/01/28 15:28:00 by onermorko        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_boyut;
	int		s2_boyut;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_boyut = ft_strlen(s1);
	s2_boyut = ft_strlen(s2);
	str = (char *)malloc((s1_boyut + s2_boyut + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1_boyut + 1);
	ft_memcpy(&str[s1_boyut], s2, s2_boyut + 1);
	return ((char *)str);
}
