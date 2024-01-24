/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:28 by kmatjuhi          #+#    #+#             */
/*   Updated: 2023/12/07 12:23:17 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_character(va_list args, char c)
{
	if (c != '%')
		c = va_arg(args, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_string(va_list args, char c)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(args, char *);
	if (s && c == 's')
	{
		while (s[i])
		{
			if (write(1, &s[i++], 1) == -1)
				return (-1);
		}
		return (i);
	}
	if (write(1, "(null)", 6) == -1)
		return (-1);
	return (6);
}

int	ft_number(va_list args, char c)
{
	long long	i;

	i = va_arg(args, int);
	if (c == 'u')
	{
		if (i < 0 && i >= -2147483648)
			i = 4294967296 + (i);
	}
	if (ft_putnbr(i) == -1)
		return (-1);
	else 
		return (length(i, 10));
}

int	ft_hex(va_list args, char c)
{
	long long	i;

	i = va_arg(args, int);
	if (i < 0 && i >= -2147483648)
		i = 4294967296 + (i);
	if (c == 'x')
	{
		if (ft_puthex(i, 87) == -1)
			return (-1);
	}
	else
	{
		if (ft_puthex(i, 55) == -1)
			return (-1);
	}
	return (length(i, 16));
}

int	ft_pointer(va_list args, char c)
{
	unsigned long long	ptr;

	if (c == 'p')
		ptr = 0;
	ptr = va_arg(args, unsigned long long);
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (ft_puthex(ptr, 87) == -1)
		return (-1);
	return (ulength(ptr, 16) + 2);
}
