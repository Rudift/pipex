/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:58:42 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/18 14:06:49 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	if (!big && len == 0)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && big[i + j] == little[j] && i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	printf("ft_strnstr : %s\n", ft_strnstr(av[1], av[2], atoi(av[3])));
	printf("strstr : %s\n", strstr(av[1], av[2]));
	printf("ft_strnstr : %p\n", ft_strnstr(av[1], av[2], atoi(av[3])));
	printf("strstr : %p\n", strstr(av[1], av[2]));

	return (0);
}*/
