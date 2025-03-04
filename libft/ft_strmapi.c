/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:59:51 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/15 15:56:45 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < ft_strlen(s))
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*static char	ft_uppercase (unsigned int i, char c)
{
	if (i != 0)
	{
		c = c - 32;
	}
	return (c);
}
int	main(int ac, char **av)
{
	if(ac != 2)
	{
		printf("Mauvais nombre d'arguments\n");
		return(0);
	}
	ft_strmapi(av[1], ft_uppercase);
	printf("%s\n", ft_strmapi(av[1], ft_uppercase));
	return (0);
}*/
