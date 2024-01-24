/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:06:30 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/20 18:00:31 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length_itoa(long int n, int neg)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	if (neg == 1)
		i++;
	return (i);
}

static char	*convert(char *dest, int i, long int n, int neg)
{
	int	mod;

	mod = 0;
	dest[i--] = '\0';
	if (n == 0)
	{
		dest[i] = 0 + '0';
		return (dest);
	}
	while (n != 0)
	{
		mod = n % 10;
		n = (n - mod) / 10;
		dest[i--] = mod + '0';
	}
	if (neg == 1)
		dest[i] = '-';
	return (dest);
}

char	*ft_itoa(int n)
{
	char		*dest;
	int			i;
	int			neg;
	long int	num;

	num = n;
	neg = 0;
	if (num < 0)
	{
		num *= -1;
		neg = 1;
	}
	i = length_itoa(num, neg);
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	dest = convert(dest, i, num, neg);
	return (dest);
}
