/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:00:53 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/06 13:38:00 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back (t_list **lst, t_list *new)
{

    while ((*(lst))->next != NULL)
		*lst = (*(lst))->next;
    if ((*(lst))->next == NULL)
		(*(lst))->next = new;
	else
    	*lst = new;
}