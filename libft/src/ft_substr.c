/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:33:13 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/03 19:39:30 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subst;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	subst = malloc((sizeof(char) * sizeof(s - start)) * len);
	while (i < start)
		i++;
	while (j < len && s[i] != '\0')
	{
		subst[j] = s[i];
		i++;
		j++;
	}	
	subst[j] = '\0';
	return (subst);
}
