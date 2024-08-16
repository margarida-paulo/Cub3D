/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:56:17 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/27 14:30:34 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = lst;
	if (!lst)
		return (0);
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	if (temp->next == NULL)
		i++;
	return (i);
}

/*int	main(void)
{
	t_list *head;
	t_list *newnode1;
	t_list *newnode2;
	t_list *newnode3;
	t_list *newnode4;
	t_list *newnode5;

	head = NULL;
	newnode1 = ft_lstnew("Do it");
	newnode2 = ft_lstnew("Just do it");
	newnode3 = ft_lstnew("Don't let your dreams be dreams");
	newnode4 = ft_lstnew("Yesterday you said tommorow");
	newnode5 = ft_lstnew("So just do it");

	ft_lstadd_front(&head, newnode5);
	ft_lstadd_front(&head, newnode4);
	ft_lstadd_front(&head, newnode3);
	ft_lstadd_front(&head, newnode2);
	ft_lstadd_front(&head, newnode1);

	printf("The list size is %d\n", ft_lstsize(head));
	printf("List of content\n");
	while (head)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
	return (0);
}
int main2(void)
{
	t list	*head;
	int		i;

	i = 0;
	head = NULL;
	while (i < 15)
	{
		ft_lstadd_front(&head, ft_lstnew(&i))
		i++;
	}
	printf("The list size is %d\n", ft_lstsize(head));
}*/
