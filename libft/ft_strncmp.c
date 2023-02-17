/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:54:20 by rloos             #+#    #+#             */
/*   Updated: 2022/10/10 09:54:38 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		if (*str1 == '\0')
			return (0);
		str1++;
		str2++;
		n--;
	}
	return (0);
}

/* int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && ((s1[i] != '\0') || (s2[i] != '\0')))
	{
		if (s1[i] != s2[i] && (s1[i] >= 0 && s2[i] >= 0))
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] < s2[i])
		{
			return (s2[i] - s1[i]);
		}
		i++;
	}
	return (0);
} */
/* 
int	main(void)
{
	printf("%d\n", ft_strncmp("zwölf", "zwalf", 10));
	printf("%d\n", strncmp("zwölf", "zlf", 10));
}
 */