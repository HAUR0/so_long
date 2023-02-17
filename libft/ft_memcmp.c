/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:30 by rloos             #+#    #+#             */
/*   Updated: 2022/10/11 12:08:09 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && str1[i] == str2[i])
		i++;
	if (i < n)
		return (str1[i] - str2[i]);
	return (0);
}

/* 
int	main(void)
{
	char	str1[1];
	char	str2[10];
	int		ret;
	int		ret2;

	memcpy(str1, "a", 6);
	memcpy(str2, "Acdef", 6);
	ret = memcmp(str1, str2, 5);
	if (ret > 0)
	{
		printf("str2 is less than str1");
	}
	else if (ret < 0)
	{
		printf("str1 is less than str2");
	}
	else
	{
		printf("str1 is equal to str2");
	}
	printf("\n");
	ret2 = ft_memcmp(str1, str2, 5);
	if (ret2 > 0)
	{
		printf("str2 is less than str1");
	}
	else if (ret2 < 0)
	{
		printf("str1 is less than str2");
	}
	else
	{
		printf("str1 is equal to str2");
	}
	return (0);
}
 */
