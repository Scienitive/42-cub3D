/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omorkoc <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:37:07 by omorkoc           #+#    #+#             */
/*   Updated: 2022/01/28 14:57:41 by onermorko        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	int	i;

	if (c >= 0 && c <= 127)
		i = 1;
	else
		i = 0;
	return (i);
}