/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:25:37 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/18 11:27:09 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		tot_size;
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	tot_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(tot_size * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{	
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{	
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}
/*int	main(int ac, char **av)
{
	char	*str;

	if (ac != 3)
		return (0);
	str = ft_strjoin(av[1], av[2]);
	printf("%s\n", str);
	free(str);
	return (0);
}*/
