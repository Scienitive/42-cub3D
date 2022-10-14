/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omorkoc <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:33:26 by omorkoc           #+#    #+#             */
/*   Updated: 2022/01/28 15:23:41 by onermorko        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str;
	int		sayi;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2", fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	sayi = n;
	sayi = sayi % 10;
	str = sayi + '0';
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(str, fd);
}
