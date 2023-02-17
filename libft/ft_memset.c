/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:14:38 by rloos             #+#    #+#             */
/*   Updated: 2022/10/04 14:14:42 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n > 0)
	{
		*str = c;
		str++;
		n--;
	}
	return (s);
}

/* 
int	main(void)
{
	char	tnt[40];

	tnt[40] = "dynamite";
	
	ft_memset(tnt, '&', 3);
	printf("%s", tnt);
	printf("\n");
	memset(tnt, '&', 3);
	printf("%s", tnt);
	return (0);
}
 */