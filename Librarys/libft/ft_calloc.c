/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onermorkoc <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:31:28 by onermorko         #+#    #+#             */
/*   Updated: 2022/01/28 14:55:44 by onermorko        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alan;

	alan = malloc(size * nmemb);
	if (!alan)
		return (0);
	ft_memset(alan, 0, size * nmemb);
	return (alan);
}
