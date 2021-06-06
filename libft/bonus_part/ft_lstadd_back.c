/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:00:53 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/06 00:07:17 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back (t_list **lst, t_list *new)
{
    t_list  *lastnode;

    lastnode = ft_lstlast(*lst);
    if (lastnode)
        lastnode->next = new;
    else
        *lst = new;
}