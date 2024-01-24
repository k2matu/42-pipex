/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:11:55 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/20 19:46:00 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	unsigned char	a;
	int				i;

	a = c;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != a)
		i++;
	if (str[i] == a)
	{
		i++;
		return (&str[i]);
	}
	return (NULL);
}
