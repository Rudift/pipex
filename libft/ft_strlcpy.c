/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:55:21 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/16 14:06:27 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	src_l;

	i = 0;
	src_l = 0;
	while (src[src_l])
		src_l++;
	if (siz == 0)
		return (src_l);
	while (src[i] && i < siz - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_l);
}

/*int	main(int ac, char **av)
{
	char	dest1[atoi(av[2])];
	char	dest2[atoi(av[2])];
	int		size1;
	int		size2;

	if (ac != 3)
		return (0);
	size1 = ft_strlcpy(dest1, av[1], atoi(av[2]));
	size2 = strlcpy(dest2, av[1], atoi(av[2]));
	printf("ft_strlcpy : %s\n size : %d\n", dest1, size1);
	printf("strlcpy : %s\n size : %d\n", dest2, size2);
	return(0);
}*/
