/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 00:25:40 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/06 13:33:49 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void(*del)(void *))
{
    t_list *temp;
    while (*lst)
    {
        temp = (*(lst))->next;
        del((*(lst))->content);
        *lst = temp;
    }
}
