/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:45:01 by rloos             #+#    #+#             */
/*   Updated: 2022/10/10 10:45:12 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (small[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == small[j])
		{
			while (i + j < len && big[i + j] == small[j])
			{
				j++;
				if (!small[j])
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}

/* 
int	main(void)
{
	char	*a;
	char	*b;

	a = "Hello";
	b = "ello";
	printf("%s", ft_strnstr(a, b, 5));
}
 */