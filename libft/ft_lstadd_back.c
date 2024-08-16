/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:53:54 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/27 14:31:47 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

/*int	main(void)
{
	t_list	*head;
	int		*value;
	int		i;
	head = NULL;
	i = 15;
	while (i > 0)
	{
		value = malloc(sizeof(int));
		*value = i;
		ft_lstadd_back(&head, ft_lstnew(value));
		i--;
	}
	printf("the content in the last node is \n",
	 *(int *)ft_lstlast(head->content));
	return (0);
}*/
