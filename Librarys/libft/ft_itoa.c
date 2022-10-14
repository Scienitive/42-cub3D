/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onermorkoc <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:58:54 by onermorko         #+#    #+#             */
/*   Updated: 2022/01/31 08:51:23 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_hesapla(int sayi)
{
	size_t	uzunluk;

	if (sayi == 0)
		return (1);
	uzunluk = 0;
	while (sayi)
	{
		sayi = sayi / 10;
		uzunluk++;
	}
	return (uzunluk);
}

char	*ft_make_array(size_t dizi_boyut)
{
	char	*dizi;

	dizi = (char *)malloc(dizi_boyut * sizeof(char));
	if (!dizi)
		return (NULL);
	dizi[dizi_boyut - 1] = '\0';
	return (dizi);
}

char	*ft_convert(char *dizi, int n, size_t dizi_boyut)
{
	int	rakam;

	while (n)
	{
		rakam = n;
		rakam = rakam % 10;
		dizi[dizi_boyut - 2] = rakam + '0';
		n = n / 10;
		dizi_boyut--;
	}
	return (dizi);
}

size_t	ft_dizi_boyut(int n)
{
	size_t	dizi_boyut;

	if (n < 0)
		dizi_boyut = ft_hesapla(n) + 2;
	else
		dizi_boyut = ft_hesapla(n) + 1;
	return (dizi_boyut);
}

char	*ft_itoa(int n)
{
	char	*dizi;
	size_t	dizi_boyut;

	dizi_boyut = ft_dizi_boyut(n);
	dizi = ft_make_array(dizi_boyut);
	if (!dizi)
		return (NULL);
	if (n == 0)
	{
		dizi[0] = '0';
		return (dizi);
	}
	if (n == -2147483648)
	{
		dizi[0] = '-';
		dizi[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		dizi[0] = '-';
		n *= -1;
	}
	return (ft_convert(dizi, n, dizi_boyut));
}
