/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:41:44 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/15 14:16:44 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int character)
{
	if (character >= 'a' && character <= 'z')
		return (8);
	if (character >= 'A' && character <= 'Z')
		return (8);
	if (character >= '0' && character <= '9')
		return (8);
	return (0);
}
/*int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf("%d\n", ft_isalnum(av[1][0]));
	printf("%d\n", isalnum(av[1][0]));
}*/
