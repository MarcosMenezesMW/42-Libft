/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:14:00 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/06 17:26:07 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (*s == c && *s)
		s++;
	while (s[i])
	{
		if (!i)
			words++;
		else if (s[i - 1] == c && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

static size_t	str_size(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**ft_free(char **str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(str[i]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	int		j;
	int		k;
	int		counter;

	counter = (count_words(s, c));
	str_array = malloc(sizeof(char *) * (counter + 1));
	j = 0;
	if (!s || !str_array)
		return (NULL);
	while (j < counter)
	{
		while (*s == c && *s)
			s++;
		k = str_size(s, c);
		str_array[j] = ft_substr(s, 0, k);
		if (!str_array[j])
			return (ft_free(str_array, j));
		s += k + 1;
		j++;
	}
	str_array[counter] = NULL;
	return (str_array);
}
