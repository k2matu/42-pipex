/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:32:05 by kmatjuhi          #+#    #+#             */
/*   Updated: 2023/11/14 10:38:27 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	len = i + ft_strlen(src);
	if (dstsize <= i)
		len = ft_strlen(src) + dstsize;
	while (i + 1 < dstsize && src[j])
		dst[i++] = src[j++];
	if (dstsize != 0)
		dst[i] = '\0';
	return (len);
}
