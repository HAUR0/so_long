/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:22 by rloos             #+#    #+#             */
/*   Updated: 2022/10/05 14:57:25 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;

	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	if (!t_dst && !t_src)
		return (0);
	if (src < dst)
	{
		t_src = &t_src[len - 1];
		t_dst = &t_dst[len - 1];
		while (len--)
			*t_dst-- = *t_src--;
	}
	else if (src >= dst)
	{
		while (len--)
			*t_dst++ = *t_src++;
	}
	return (dst);
}

/*  
int	main(void)
{
	char	dst[50];
	char	src[50];
	char	t_dst[50];
	char	t_src[50];

	dst[50] = "Test";
	src[50] = "Zero";
	
	t_dst[50] = "Test";
	t_src[50] = "Zero";
	
	ft_memmove(dst, src, 50);
	printf("%s\n", dst);
	
	memmove(t_dst, t_src, 50);
	printf("%s", t_dst);
}
*/