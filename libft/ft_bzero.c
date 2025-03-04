/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:41:06 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/15 14:25:04 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*scopy;

	i = 0;
	scopy = (unsigned char *)s;
	while (i < n)
	{
		scopy[i] = '\0';
		i++;
	}
}
/*int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
int	main(int ac, char **av)
{
	int	i;
	int	size;

	if(ac != 3)
		return (0);
	i = 0;
	size = ft_strlen(av[1]);
	ft_bzero(av[1], atoi(av[2]));
	while (i < size)
	{
		write (1, &av[1][i], 1);
		i++;
	}
	return (0);
}*/
