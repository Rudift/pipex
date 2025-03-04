/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:42:17 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/18 13:46:18 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (size && (nmemb > SIZE_MAX / size))
		return (NULL);
	s = malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_bzero (s, nmemb * size);
	return (s);
}
/*int	main(void)
{
	int	*tab1 = (int *)ft_calloc(10, sizeof(int));
	int	*tab2 = (int *)calloc(10, sizeof(int));
	size_t	i = 0;

	printf("ft_calloc :\n");
	while (i < 10)
	{
		printf("%d\n", tab1[i]);
		i++;
	}
	printf("calloc :\n");
	i = 0;
	while (i < 10)
	{
		printf("%d\n", tab2[i]);
		i++;
	}
	free(tab1);
	free(tab2);
}*/
