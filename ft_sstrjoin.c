/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:21:59 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/02/28 11:22:50 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_sstrjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 4) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i++] = '/';
	while (*s2)
		dest[i++] = *s2++;
	dest[i] = '\0';
	free(s1);
	return (dest);
}
