/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:52:36 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/15 14:35:34 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
	{
		return (c - 32);
	}
	else
		return (c);
}
/*int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf("%c\n", ft_toupper((int)av[1][0]));
	printf("%c\n", toupper((int)av[1][0]));
	return (0);
}*/
