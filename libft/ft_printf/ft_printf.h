/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:13:13 by kmatjuhi          #+#    #+#             */
/*   Updated: 2023/12/11 17:40:21 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION "csiduxXp%"

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_character(va_list args, char c);
int	ft_string(va_list args, char c);
int	ft_number(va_list args, char c);
int	ft_hex(va_list args, char c);
int	ft_pointer(va_list args, char c);
int	ft_putnbr(long long n);
int	ft_puthex(unsigned long long n, int i);
int	length(long long num, int base);
int	ulength(unsigned long long num, int base);

typedef int				(*t_printf)(va_list, char);

static const t_printf	g_printf[9] = {
	ft_character,
	ft_string,
	ft_number,
	ft_number,
	ft_number,
	ft_hex,
	ft_hex,
	ft_pointer,
	ft_character
};

#endif
