/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:19:21 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/16 14:27:36 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strdup(const char *s)
{
	char		*str;
	int			srcl;
	size_t		i;

	i = 0;
	srcl = ft_strlen(s);
	str = (char *)malloc((srcl + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*int	main (int ac, char **av)
{
	if(ac != 2)
		return (0);
	char	*dup1;
	char	*dup2;

	dup1 = ft_strdup((const char *)av[1]);
	dup2 = strdup((const char *)av[1]);

	printf("ft_strdup : %s\n", dup1);
	printf("strdup : %s\n", dup2);
	free(dup1);
	free(dup2);
	return(0);
}*/
