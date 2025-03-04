/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:04:02 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/18 15:30:27 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbmot(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			count++;
		}
		i++;
	}
	return (count);
}

static int	ft_strlen_c(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	*ft_strcdup(const char *s, char c)
{
	int		size;
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen_c(s, c);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < size)
	{
		if (s[i] != c)
		{				
			res[j] = s[i];
			j++;
		}
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		nbmot;

	nbmot = ft_nbmot(s, c);
	tab = (char **)malloc ((nbmot + 1) * sizeof (char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (nbmot != 0)
	{
		while (*s == c)
			s++;
		tab[i] = ft_strcdup(s, c);
		s = ft_strchr(s, c) + 1;
		i++;
		nbmot -= 1;
	}
	tab[i] = NULL;
	return (tab);
}
/*int	main(int ac, char **av)
{
	int		i;
	char	**tab;

	if(ac != 3)
		return(0);
	tab = ft_split(av[1], av[2][0]);
	i = 0;
	printf("Nombre de mots : %d\n", ft_nbmot(av[1], av[2][0]));
	while (i < ft_nbmot(av[1], av[2][0]))
	{
		printf("%s\n", tab[i]);
		i++;
	}
	i = 0;
	while (i < ft_nbmot(av[1], av[2][0]))
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}*/
