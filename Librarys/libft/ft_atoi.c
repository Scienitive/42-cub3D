/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onermorkoc <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:45:12 by onermorko         #+#    #+#             */
/*   Updated: 2022/01/31 08:33:44 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sayi;
	int	isaret;

	sayi = 0;
	isaret = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || \
	*str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			isaret *= -1;
		str++;
	}
	if (*str == '+' || *str == '-')
		return (0);
	while (*str && *str >= '0' && *str <= '9')
	{
		sayi = (sayi * 10) + (*str - '0');
		str++;
	}
	return (isaret * sayi);
}
