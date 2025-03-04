/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:14:55 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/16 17:49:51 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_l;
	size_t	src_l;

	if (!dst && size == 0)
		return (0);
	src_l = ft_strlen(src);
	dst_l = ft_strlen(dst);
	i = 0;
	if (dst_l < size - 1 && size > 0)
	{
		while (src[i] != '\0' && (dst_l + i) < size - 1)
		{
			dst[dst_l + i] = src[i];
			i++;
		}
		dst[dst_l + i] = '\0';
	}
	if (size <= dst_l)
		dst_l = size;
	return (dst_l + src_l);
}
/*int	main(void)
{
	char	dest1[20] = "Pinpin ";
	char	dest2[20] = "Pinpin ";
	char	src1[] = "le lapin";
	char	src2[] = "le lapin";
	size_t	size1;
	size_t	size2;

	size1 = ft_strlcat(dest1, src1, 20);		
	size2 = strlcat(dest2, src2, 20);
	printf("%s, %ld\n", dest1, size1);
	printf("%s, %ld\n", dest2, size2);
}*/
