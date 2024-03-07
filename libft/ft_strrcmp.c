/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:17:09 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/06 21:38:40 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - ft_strlen(s2);
	while (s1[j] == s2[i] && s1[j] != '\0')
	{
		i++;
		j++;
	}
	if (s1[j] == s2[i])
		return (0);
	else
		return (s1[j] - s2[i]);
}
