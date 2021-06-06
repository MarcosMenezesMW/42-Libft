/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 00:25:40 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/06 01:12:24 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void(*del)(void *))
{
    t_list *temp;
    while (*lst)
    {
        temp = (*(lst))->next;
        ft_lstdelone(*lst, del);
        *lst = temp;
    }
}
