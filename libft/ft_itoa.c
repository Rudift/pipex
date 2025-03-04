/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:15:16 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/16 16:52:05 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizeint(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*ft_mallocator(int size)
{
	char	*str;

	str = (char *) malloc((size + 1) * sizeof(char));
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = n;
	size = ft_sizeint (n);
	str = ft_mallocator (size);
	if (!str)
		return (NULL);
	if (n < 0)
		nb = -n;
	str[size] = '\0';
	size--;
	if (n == 0)
		str[size] = '0';
	while (nb > 0)
	{
		str[size--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (n < 0)
		str[size] = '-';
	return (str);
}
/*
int	main(int ac, char **av)
{
	char	*str;

	if (ac != 2)
		return (0);
	str = ft_itoa(atoi(av[1]));
	printf("taille de l'int : %d\n", ft_sizeint(atoi(av[1])));
	printf("%s\n", str);
	free (str);
	return (0);
}*/
