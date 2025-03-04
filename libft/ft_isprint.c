/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:59:53 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/15 16:21:14 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (16384);
	else
		return (0);
}
/*int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf("%d\n", ft_isprint(av[1][0]));
	printf("%d\n", isprint(av[1][0]));
}*/
