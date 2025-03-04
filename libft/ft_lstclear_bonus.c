/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:54:23 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/19 13:16:39 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
/*
void	del(void *content)
{
	free(content);
}

t_list	*lst_new(void *content)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return node; 
}

int	main(void)
{
	t_list	*head = lst_new(ft_strdup("Node 1"));
		if(!head)
			return (0);
	head->next = lst_new(ft_strdup("Node 2"));
		if(!head->next)
			return (0);
	head->next->next = lst_new(ft_strdup("Node 3"));
		if(!head->next->next)
			return (0);
	printf("Contenu de la liste avant clear :\n");
	t_list *temp = head;
	while (temp)
	{
		printf ("- %s\n", (char *)temp->content);
		temp = temp->next;
	}

	ft_lstclear(&head, del);

	if (!head)
		printf("vide intersideral\n");	
}*/
