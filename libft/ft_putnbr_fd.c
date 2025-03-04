/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:52:24 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/15 16:27:53 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write (fd, "-2", 2);
		ft_putnbr_fd (147483648, fd);
	}
	else if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
		ft_putnbr_fd (n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putchar_fd (n % 10 + 48, fd);
	}
	else
		ft_putchar_fd (n + 48, fd);
}
/*int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	ft_putnbr_fd(atoi(av[1]), atoi(av[2]));
	return (0);
}*/
