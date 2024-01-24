/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:19:50 by kmatjuhi          #+#    #+#             */
/*   Updated: 2023/12/07 12:23:35 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	length(long long num, int base)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= base;
		i++;
	}
	return (i);
}

int	ulength(unsigned long long num, int base)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= base;
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned long long n, int i)
{
	if (n > 15)
	{
		if (ft_puthex((n / 16), i) == -1)
			return (-1);
		if (ft_puthex((n % 16), i) == -1)
			return (-1);
	}
	else
	{
		if (n > 9 && n < 16)
			n = n + i;
		else
			n = n + '0';
		if (write(1, &n, 1) == -1)
			return (-1);
	}
	return (0);
}

int	ft_putnbr(long long n)
{
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		if (ft_putnbr(n * -1) == -1)
			return (-1);
	}
	else if (n > 9)
	{
		if (ft_putnbr(n / 10) == -1)
			return (-1);
		if (ft_putnbr(n % 10) == -1)
			return (-1);
	}
	else
	{
		n = n + '0';
		if (write(1, &n, 1) == -1)
			return (-1);
	}
	return (0);
}
