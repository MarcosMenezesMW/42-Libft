/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:05:14 by user42            #+#    #+#             */
/*   Updated: 2021/06/03 19:21:00 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	h;
	int		k;

	i = 0;
	j = ft_strlen(src);
	h = ft_strlen(dst);
	k = j + h;
	if (size > h)
	{
		while (src[i] != '\0' && h + 1 < size)
			dst[h++] = src[i++];
		dst[h] = '\0';
		return (k);
	}
	if (size == h)
		return (j + ft_strlen(dst));
	return (j + size);
}
