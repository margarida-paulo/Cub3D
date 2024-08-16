/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:36:08 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/27 16:13:17 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

/*int	main(void)
{
	t_list *head;
	t_list *new_node1;
	t_list *new_node2;
	t_list *new_node3;
	t_list *new_node4;

	head = NULL;
	new_node1 = ft_lstnew("Ealine Dickinson:");
	new_node2 = ft_lstnew(""A hospital? What is it?"");
	new_node3 = ft_lstnew("Rumack:");
	new_node4 = ft_lstnew(""It's a big building with patients, but that's not
	important right now"");

	ft_lstadd_front(&head, new_node4);
	ft_lstadd_front(&head, new_node3);
	ft_lstadd_front(&head, new_node2);
	ft_lstadd_front(&head, new_node1);

	printf("List of content: \n");
	while (head != NULL)
	{
		printf("%s\n", head -> content);
		head = head -> next;
	}
	return (0);
}*/
