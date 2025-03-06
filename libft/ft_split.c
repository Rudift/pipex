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

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen_c(s, c);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_splitinette(char **tab, char const *s, char c, int nbmot)
{
	int	i;

	i = 0;
	while (i++ < nbmot)
	{
		while (*s == c)
			s++;
		tab[i] = ft_strcdup(s, c);
		if (!tab[i])
		{
			ft_freetab(tab);
			return (NULL);
		}
		s = ft_strchr(s, c);
		if (s)
			s++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nbmot;

	if (!s)
		return (NULL);
	nbmot = ft_nbmot(s, c);
	tab = (char **)malloc ((nbmot + 1) * sizeof (char *));
	if (!tab)
		return (NULL);
	ft_splitinette(tab, s, c, nbmot);
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
