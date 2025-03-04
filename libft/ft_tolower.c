/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:13:53 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/15 14:36:40 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
	{
		return (c + 32);
	}
	else
		return (c);
}
/*int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf("%c\n", ft_tolower((int)av[1][0]));
	printf("%c\n", tolower((int)av[1][0]));
	return (0);
}*/
