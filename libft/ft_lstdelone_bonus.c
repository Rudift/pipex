/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:35:01 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/19 10:51:36 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
void	del(void *content)
{
	free(content);
}

int	main (void)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (1);
	node->content = ft_strdup("I'll be back !");
	node->next = NULL;
	printf("%s\n",(char *)node->content);
	ft_lstdelone(node, del);
	printf("%s\n", (char * )node->content);
}*/
