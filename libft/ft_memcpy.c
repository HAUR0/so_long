/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:30 by rloos             #+#    #+#             */
/*   Updated: 2022/10/05 09:26:40 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dst_ptr;
	char			*src_ptr;
	unsigned int	i;

	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	i = 0;
	if (!dst && !src)
	{
		return (NULL);
	}
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}

/* 
int	main(void)
{
	char	*dst;
	char	*src;
	char	*dst2;
	char	*src2;

	dst = "test";
	src = "Zero";
	
	dst2 = "test";
	src2 = "Zero";
	
	ft_memcpy(dst, src, 50);
	printf("%s\n", dst);
	memcpy(dst2, src2, 50);
	printf("%s", dst2);
}
 */