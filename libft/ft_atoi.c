/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:21:35 by kmatjuhi          #+#    #+#             */
/*   Updated: 2023/12/19 17:04:58 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	size_t	n;
	size_t	max_nbr;
	int		negative;

	i = 0;
	n = 0;
	negative = 1;
	max_nbr = 0 - 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (n > (max_nbr / 10 - str[i] - '0') && negative == 1)
			return (-1);
		if (n > (max_nbr / 10 - str[i] - '0') && negative == -1)
			return (0);
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * negative);
}
