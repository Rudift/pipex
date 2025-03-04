/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:38:56 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/18 15:13:12 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	i = 0;
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	while (i < n)
	{
		if (s1c[i] < s2c[i])
			return (-1);
		else if (s1c[i] > s2c[i])
			return (1);
		i++;
	}
	return (0);
}
/*int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	printf("ft_memcmp :%d\n", ft_memcmp(av[1], av[2], atoi(av[3])));
	printf("memcmp : %d\n", memcmp(av[1], av[2], atoi(av[3])));
	return (0);
}*/
