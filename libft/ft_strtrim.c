/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:50:35 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/16 15:29:19 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int	ft_isset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_isset(set, s1[start]))
		start ++;
	while (end > start && ft_isset (set, s1[end - 1]))
		end --;
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	ft_strlcpy (res, s1 + start, end - start + 1);
	return (res);
}
/*int	main(int ac, char **av)
{
	char	*str = ft_strtrim(av[1], av[2]);
	if (ac != 3)
		return (0);
	printf("%s\n", str);
	free(str);
	return (0);
}*/
