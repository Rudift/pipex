/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:45:49 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/19 13:09:55 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*n_node;
	void	*n_content;

	n_lst = NULL;
	while (lst)
	{
		n_content = f(lst->content);
		if (!n_content)
		{
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		n_node = ft_lstnew(n_content);
		if (!n_content)
		{
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&n_lst, n_node);
		lst = lst -> next;
	}
	return (n_lst);
}
