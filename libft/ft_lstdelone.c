/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:38:36 by plashkar          #+#    #+#             */
/*   Updated: 2023/05/01 13:30:29 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

/*int main(void)
{
	t_list *head;

	head = ft_lstnew("Node 2");
	ft_lstadd_front(&head, ft_lstnew("Node3"));
	ft_lstadd_back(&head, ft_lstnew("Node1"));
	ft_lstadd_front(&head, ft_lstnew("Node 4"));

	printf("List of content: \n");
	while (head != NULL)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}

		t_list *second_node = head->next;
	ft_lstdelone(second_node, &del);

	t_list *current_node = head;
	while (current_node != NULL)
	{
		printf("%s\n", (char *)current_node->content);
		current_node = current_node->next;
	}
	ft_lstclear(&head, &del);
	return (0);

	void del(void *content)
{
	free(content);
}
}*/
