/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:05:27 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/15 14:17:40 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int character)
{
	if (character >= 'a' && character <= 'z')
		return (1024);
	if (character >= 'A' && character <= 'Z')
		return (1024);
	return (0);
}
/*int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf("%d\n", ft_isalpha(av[1][0]));
	printf("%d\n", isalpha(av[1][0]));
}*/
