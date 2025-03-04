/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:22:41 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/15 14:23:56 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*scopy;

	i = 0;
	scopy = (unsigned char *)s;
	while (i < n)
	{
		scopy[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*int	main(void)
{
	char			s1[20];
	char			s2[20];
	unsigned long	i;

	i = 0;
	ft_memset(s1, 's', 10 * sizeof(char));
	memset(s2, 's', 10 * sizeof(char));
	printf("ft_memset : \n\n");
	while (i < 10)
	{
		printf("%c\n", s1[i]);
		i++;
	}
	i = 0;
	printf("memset : \n\n");
	while (i < 10)
	{
		printf("%c\n", s2[i]);
		i++;
	}
}*/
