/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:43:28 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/18 11:58:18 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	i++;
	while (i != 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		i--;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
/*int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	printf("%p\n", ft_strrchr(av[1], av[2][0])); 
	printf("%p\n", strrchr(av[1], av[2][0]));
	return (0); 
}*/
