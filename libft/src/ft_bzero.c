/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:01:46 by user42            #+#    #+#             */
/*   Updated: 2021/06/03 19:37:18 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*p_str;

	p_str = str;
	while (n > 0)
	{
		*p_str = '\0';
		p_str++;
		n--;
	}
}
