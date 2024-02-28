/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 06:53:37 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/02/28 11:51:38 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first_pos(char const *s1, char const c)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] != c)
		i++;
	if (s1[i] == c)
		i++;
	return (i);
}

static int	last_pos(char const *s1, char const c)
{
	int	i;

	i = ft_strlen(s1);
	while (i > 0 && s1[i] != c)
		i--;
	return (i);
}

char	*ft_trimstr(char const *s1, char const c)
{
	int		first;
	int		last;
	int		len;
	char	*dest;

	first = first_pos(s1, c);
	last = last_pos(s1, c);
	len = last - first;
	if (len <= 0)
	{
		dest = (char *)malloc(sizeof(char) * 1);
		if (!dest)
			return (NULL);
	}
	if (len <= 0)
		return (NULL);
	dest = ft_substr(s1, first, len);
	return (dest);
}
