/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:25:25 by mvalerio          #+#    #+#             */
/*   Updated: 2023/08/11 16:16:45 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*newnode;

	if (!(lst))
		return (NULL);
	head = (t_list *)malloc(sizeof(t_list *));
	if (!head)
		return (NULL);
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&newnode, head);
		lst = lst->next;
	}
	return (head);
}
