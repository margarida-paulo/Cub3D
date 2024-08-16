/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:33:31 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/27 14:33:50 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lastnode;

	if (!lst)
		return (NULL);
	lastnode = lst;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	return (lastnode);
}

/*int	main(void)
{
	t_list	*head;
	int		i;
	int		*value;

	head = NULL;
	i = 15;
	while (i > 0)
	{
		value = malloc(sizeof(int));
		*value = i;
		ft_lstadd_front(&head, ft_lstnew(value));
		i--;
	}
	printf("the content in the last node is %d\n",
	 *(int *)ft_lstlast(head)->content);
	return (0);
}*/
