/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:14:00 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/03 18:55:57 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static char	**ft_strarray(char const *s, char c)
{
	size_t		counter;
	char		**str;

	counter = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			counter++;
			s++;
		}
	}
	str = (char **)malloc((counter + 1) * sizeof(char *));
	return (str);
}

static int	str_size(const char *s, int start, char c)
{
	int	i;

	i = 0;
	while (s[start] != c && s[start++] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	int		j;
	int		k;
	int		counter;

	str_array = ft_strarray(s, c);
	j = 0;
	counter = 0;
	if (!s || !str_array)
		return (NULL);
	while (s[j] != '\0')
	{
		if (s[j] == c && s[j] != '\0')
			j++;
		else
		{
			k = 0;
			str_array[counter] = malloc(sizeof(char) * (str_size(s, j, c) + 1));
			while (s[j] != c && s[j] != '\0')
				str_array[counter][k++] = s[j++];
			str_array[counter++][k] = '\0';
		}
	}
	str_array[counter] = NULL;
	return (str_array);
}
