/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 01:19:59 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/06 13:42:11 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
    t_list	*new_element;
	t_list	*lst_element;
	
	lst_element = NULL;
	while (lst)
	{
		new_element = malloc(sizeof(t_list));
		new_element = f(lst->content);
		if (!new_element)
		{
			del(lst_element->content);
			free(lst_element);
		}
		while (lst_element->next != NULL)
			lst_element = lst_element->next;
		lst_element->next = new_element;
		lst = lst->next;
	}
	return (lst_element);
}