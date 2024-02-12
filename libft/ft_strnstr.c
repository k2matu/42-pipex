/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:39:47 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/02/12 09:59:01 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_needle;

	i = 0;
	j = 0;
	len_needle = ft_strlen(needle);
	if (!haystack[i] && !needle[i])
		return ((char *) haystack);
	if (len < len_needle)
		return (NULL);
	if (!needle[i])
		return ((char *) haystack);
	while (i < len && haystack[i])
	{
		while (haystack[i + j] == needle[j] && i <= len - (len_needle))
		{
			j++;
			if (needle[j] == '\0')
				return ((char *) haystack + i);
		}
		j = 0;
		i++;
	}
	return (0);
}
