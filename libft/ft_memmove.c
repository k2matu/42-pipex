/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:47:47 by kmatjuhi          #+#    #+#             */
/*   Updated: 2023/11/07 20:45:21 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*str;

	dest = (unsigned char *)dst;
	str = (unsigned char *)src;
	if ((!dst && !src) || len == 0)
		return (dst);
	if (src < dst)
	{
		while (len--)
			dest[len] = str[len];
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
